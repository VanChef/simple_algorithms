/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月04日 10时45分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

typedef struct _tag_mp4box_
{
    union size_byte
    {
        int size;
        char byte[4];
    };
    int type;
}mp4box;

int check_box_type_has_child(char *type)
{
    if ((type[0] == 'm') &&
        (type[1] == 'o') &&
        (type[2] == 'o') &&
        (type[3] == 'f'))
        return 1;
    else if
        ((type[0] == 't') &&
        (type[1] == 'r') &&
        (type[2] == 'a') &&
        (type[3] == 'f'))
        return 1;
    else if
        ((type[0] == 'm') &&
        (type[1] == 'o') &&
        (type[2] == 'o') &&
        (type[3] == 'v'))
        return 1;
    else
        return 0;
}

static int box_depth = 0;
static char buf[1024];

int read_mov_box(FILE *f)
{
    int size_tmp, size, i;
    char type[4];
    if (4 != fread(&size_tmp, sizeof(char), 4, f))
        return -1;
    
    if (4 != fread(type, sizeof(char), 4, f))
        return -1;

    size = 0;
    size = (size_tmp&0xFF)<<24 | (size_tmp&0xFF00)<<8 | (size_tmp&0xFF0000)>>8 | (size_tmp&0xFF000000)>>24;

    for (i = 0; i < box_depth; i++)
        printf("\t");
    printf("type %c%c%c%c\tsize %d\n", type[0], type[1], type[2], type[3], size);

    if (check_box_type_has_child(type))
    {   
        box_depth ++;
        printf("+++");
        read_mov_box(f);
        box_depth --;
    }
    else
    {
        if ((type[0] == 'm') && (type[1] == 'v') && (type[2] == 'h') && (type[3] == 'd')) {
            //read full box
            char version;
            fread(&version, sizeof(char), 1, f);        printf("version %d\n", (int)version);
            fread(buf, sizeof(char), 3, f);             printf("flag %d, %d, %d\n", buf[0], buf[1], buf[2]);

            if (version==1) {
                fread(buf, sizeof(char), 8, f);
                printf("create time %d,%d,%d,%d,%d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);

                fread(buf, sizeof(char), 8, f);
                printf("modification time %d,%d,%d,%d,%d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);

                fread(buf, sizeof(char), 4, f);
                printf("time scale %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);

                fread(buf, sizeof(char), 8, f);
                printf("duration %d,%d,%d,%d,%d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
            } else {
                fread(buf, sizeof(char), 4, f);
                printf("create time %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);

                fread(buf, sizeof(char), 4, f);
                printf("modification time %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);

                fread(buf, sizeof(char), 4, f);
                printf("time scale %x,%x,%x,%x\n", buf[0],buf[1],buf[2],buf[3]);

                fread(buf, sizeof(char), 4, f);
                printf("duration %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);
            }

            fread(buf, sizeof(char), 4, f);
            printf("rate %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);

            fread(buf, sizeof(char), 2, f);
            printf("volume %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);

            fread(buf, sizeof(char), 10, f);

            for (int i = 0; i < 9; i++) {
                fread(buf, sizeof(char), 4, f);
                printf("matrix[%d] %d,%d,%d,%d\n", i, buf[0],buf[1],buf[2],buf[3]);
            }

            for (int i = 0; i < 6; i++) {
                fread(buf, sizeof(char), 4, f);
                printf("pre def[%d] %d,%d,%d,%d\n", i, buf[0],buf[1],buf[2],buf[3]);
            }

            fread(buf, sizeof(char), 4, f);
            printf("next track id %d,%d,%d,%d\n", buf[0],buf[1],buf[2],buf[3]);
        }
        else {
            fseek(f, size - 8, SEEK_CUR);//minus type&size
        }
        return 0;
    }
}


int main (int argc, char *argv[])
{
    unsigned int size, size_tmp, type;
    FILE *f = fopen(argv[1], "rb");

    if (!f)
    {
        printf("file open failed!\n");
    }


    while (1)
    {
        if (read_mov_box(f) < 0)
            break;
    }

    if (f)
        fclose(f);
}



