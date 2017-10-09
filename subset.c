
/*
   问题：从数组n个元素中取m个元素，打印出所有可能性
   
   这个问题也是递归的经典应用。
   分析：从n个元素中取m个数，可以转化为：
   先从n个元素中选定一个元素，然后该问题即降维成：“从n-1个元素中选取m-1个元素，有几种可能”
   显然，这样就形成了递归。
   再考虑递归的终止条件，如果从n-x中选取m-x个元素，而m-x==1，那么即不必要进一步的递归，而将n-x个数依次选取即可
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
//n个元素中取m个数
void combine(int n, int m, int a[], int b[], const int M)
{
    printf("n %d, m %d\n", n, m);
    for (int j = n; j >= m; j--)
    {
        b[m - 1] = j - 1;//保存角标j-1，意味着先固定一个数，然后从剩下的j-1个数中取m-1个数，即可形成迭代
        if (m > 1)
            combine(j - 1, m - 1, a , b, M);//用到了递归思想，j-1个元素中取m-1个数
        else //当m为1的时候，意味着“从n个数中取1个数”，这样将从j-1到m的所有数依次打印即可
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

