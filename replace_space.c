/*

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

*/

#include <stdio.h>
#include <stdlib.h>

void replace_space(char *str, int length)
{

    int space_count = 0;
    for (int i = 0; i < length; i ++)
    {
        if (str[i] == ' ') {
            space_count ++;
        }
    }

    int ptr = length + space_count * 2 - 1;
    for (int i = length - 1; i >= 0; i --)
    {
        if (str[i] !=  ' ') {
            str[ptr--] = str[i];
        }
        else {
            str[ptr--] = '0'; 
            str[ptr--] = '2'; 
            str[ptr--] = '%'; 
        }
    }
    str[length + space_count * 2] = '\0';
}

int main()
{
    char *str = malloc(1024);

    snprintf(str, 1024, "%s", "We are Happy");


    replace_space(str, 12);
    
    printf("result: %s\n", str);

    free(str);
    return 0;
}

