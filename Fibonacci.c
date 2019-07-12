/*
 * =====================================================================================
 *
 *       Filename:  Fibonacci.c
 *
 *    Description:  用“菲波那切数列”解决上楼梯的问题，即n级台阶，每次上1级或2级，一共多少种可能
 *                  f(n) = f(n - 1) + f(n - 2)
 *                  一级台阶就一种可能，所以初始值t1 = 1，
 *                  2级台阶两种，所以初始值t2 = 2，
 *                  以第三级为例，可以从第一级+2，也可以从第二级+1，所以，“可能性”就是t1 + t2
 *
 *
 *        Version:  1.0
 *        Created:  04/12/2017 11:40:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int getResultByRecursion(int n) 
{
    if (n < 1) {
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }
    return getResultByRecursion(n-1) + getResultByRecursion(n-2);
}

int main()
{
    int i,j,k;

    int n = 20;
    int ret;

    int t1 = 1, t2 = 2;

    for (i = 3; i <= n; i ++) {
        ret = t1 + t2;
        printf("t1 %d t2 %d, ret %d, i %d\n", t1, t2, ret, i);
        t1 = t2;
        t2 = ret;
    }

    printf("%d\n", ret);

    ret = getResultByRecursion(20);

    printf("%d\n", ret);
}



