
/*
剑指offer上一道题
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

分析：这是一道考察细节实现的题目，一定要考虑到异常情况，如指数为0，为负的情况

*/

#include <iostream>

using namespace std;

double double_exp(double base, int exp)
{
    int sign = 1;
    if (exp == 0)
        return 1.0f;

    if (exp < 0) {
        sign = -1;
        exp = -exp;
    }

    double result = 1.0f;
    for (int i = 0; i < exp; i++) {
        result = result * base;
    }

    if (sign == -1) {
        result = 1.0f / result;
    }

    return result;
}

int main()
{
    double result;

    result = double_exp(55.6f, 4);

    cout<<"result "<<result<<endl;

    return 0;
}


