
/*
链接：https://www.nowcoder.com/questionTerminal/49cb3d0b28954deca7565b8db92c5296
来源：牛客网

[编程题]最大的奇约数
热度指数：31722时间限制：1秒空间限制：32768K
 算法知识视频讲解
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7 
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。 
输入描述:

输入一个整数N (1 ≤ N ≤ 1000000000)


输出描述:

输出一个整数，即为f(1) + f(2) + f(3).......f(N)
示例1
输入

7
输出

21
*/

#include <iostream>

using namespace std;

int max_odd_divisor(int n)
{
    if ((n % 2) == 1)
    {
        return n;
    }

    while ((n % 2) == 0)
    {
        n = n / 2;
    }

    return n;
}

int main()
{
    int test = 7;
    int result = 0;

    for (int i = 1; i <= test; i++)
    {
        result += max_odd_divisor(i);
    }
    cout<<"result "<<result<<endl;

    return 0;
}


