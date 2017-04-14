/*
 * =====================================================================================
 *
 *       Filename:  exact_float.c
 *
 *    Description:  精确表达浮点数
 *
 *        Version:  1.0
 *        Created:  04/12/2017 18:20:25
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

int main(int argc, char *argv[]) {

    int n, m;
    int i, j, k;

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    printf("n %d, m %d\n", n, m);

    printf("%d.", n / m);
    n = n % m;
    n = n * 10;

    if (n == 0)
        printf("0");
    else {
        i = 0;
        while (1) {
            printf("%d", n / m);
            n = n % m;
            n = n * 10;
            i ++;
            if (i >= 100)
                break;
        }
    }

    printf("\n");
    return 0L;    
}


