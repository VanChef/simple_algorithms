
/*

   经常在数字相关算法题中用到的子问题，判断一个数是否为质数，即只能被1和自身整除的数

   注意不要对0取余(%),会导致
   Floating point exception: 8
*/


#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeNumber(int n)
{
    for (int i = 2; i <= (int)sqrt((float)n); i++)
    {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    for (int i = 1; i < 100; i ++) {
        if (isPrimeNumber(i))
            cout<<i<<", ";
    }
    cout<<endl;

    return 0;
}


