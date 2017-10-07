
/*

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

分析：不让用循环就是不让直接暴力算，不让用乘除法，是不让用等差数列的公式算，就是另一到递归题了

*/

#include <stdio.h>

int add(int n)
{
    if (n == 1)
        return 1;
    else 
        return add(n - 1) + n;
}

int main()
{
    printf("result %d\n", add(5));
    return 0;
}



