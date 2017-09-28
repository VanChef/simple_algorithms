
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
//n个元素中取m个数
void combine(int n,int m,int a[],int b[],const int M)
{
    for(int j = n; j >= m; j--)
    {
        b[m - 1] = j - 1;//保存角标j-1
        if (m > 1)
            combine(j - 1, m - 1, a , b, M);//用到了递归思想，j-1个元素中取m-1个数
        else
        {
            for (int i = M - 1; i >= 0; i--)
                printf("%d ", a[b[i]]);
            printf("\n");
        }
    }
}

int main()
{
    int n = 10, m = 3;
    int b[3];
    int a[10] = {1,2,3,4,5,6,7,8,9,10};  

    for(int i = 0; i < n; i++)
        a[i]=i+1;

    const int M = m;
    combine(n, m, a, b, M);
}  

