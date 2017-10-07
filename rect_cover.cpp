/*
剑指offer上一道题：

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 

这个还是Fibonacci数列问题，见Fibonacci.c，需要注意整数溢出问题
这里给出递归实现的方式
*/

#include <iostream>

using namespace std;

int rect_cover(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return rect_cover(n - 2) + rect_cover(n - 1);
}


int main()
{
    int ret = rect_cover(20);

    cout<<"result "<<ret<<endl;

    return 0;
}

