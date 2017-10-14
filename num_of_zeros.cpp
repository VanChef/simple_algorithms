
/*

链接：https://www.nowcoder.com/questionTerminal/6ffdd7e4197c403e88c6a8aa3e7a332a
来源：牛客网

[编程题]末尾0的个数

输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2 
输入描述:

输入为一行，n(1 ≤ n ≤ 1000)


输出描述:

输出一个整数,即题目所求
示例1
输入

10
输出

2
*/

#include <iostream>
#include <math.h>

using namespace std;

int number_of_zeros(int n)
{
    int number_of_two = 0;
    int number_of_five = 0;
    int j;

    for (int i = 1; i <= n; i++) {
        j = i;
        while ((!(j % 2)) && (j >= 2))
        {
            number_of_two++;
            j = j / 2;
        }
        j = i;
        cout<<"i "<<i<<" number_of_two "<<number_of_two<<" number_of_five "<<number_of_five<<endl;
        while ((!(j % 5)) && (j >= 5))
        {
            number_of_five++;
            j = j / 5;
        }
        cout<<"i "<<i<<" number_of_two "<<number_of_two<<" number_of_five "<<number_of_five<<endl;
    }

    return number_of_two < number_of_five ? number_of_two : number_of_five;
}


int main()
{
    int ret;

    ret = number_of_zeros(10);
    cout<<"result "<<ret<<endl;

    return 0;
}

