/*
 *
 * c语言二维数组相关语法
 */

#include <stdlib.h>
#include <stdio.h>


//其中in的第一个维度4可以省略，第二个及更高的维度不能省略
void two_dim_array(int in[4][4], int width, int height)
{
    int i,j,k;

    for (i = 0; i < width; i++) {
        printf("%d, ", in[0][i]);
    }

    for (j = 1; j < height - 2; j++) {
        printf("%d, ", in[j][width - j]);
    }

    for (k = width - 1; k >= 0; k--) {
        printf("%d, ", in[height - 1][k]);
    }

    if ((width - 2) < 1 && (height - 2) < 1)
        return;

    //if ((width - 2) >= 1 || (height - 2) >= 1)
    //    spiral_matrix(&&in[1][1], width - 2, height - 2);
}

int main()
{
    int test[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };


    two_dim_array(test, 4, 4);
}


