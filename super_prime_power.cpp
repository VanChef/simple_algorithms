/*
链接：https://www.nowcoder.com/questionTerminal/fb511c3f1ac447309368d7e5432c6c79
来源：牛客网

如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,如果n是一个超级素数幂需要找出对应的p,q。 
输入描述:

输入一个正整数n(2 ≤ n ≤ 10^18)

输出描述:

如果n是一个超级素数幂则输出p,q,以空格分隔,行末无空格。如果n不是超级素数幂，则输出No
示例1
输入

27
输出

3 3
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

//由于p的q次方为n，而q>1，q最小为2，那么最大的p即为n开方
char *super_prime_power(int n)
{
    const int min_q = 2;
    int max_p = sqrt(n);
    char *result = (char *)malloc(10);
    memset(result, 0, 10);

    cout <<"n "<<n<<" max_p "<<max_p<<endl;

    for (int p = 2; p <= max_p; p++) {
        if (!isPrimeNumber(p))
            continue;

        int q = 2;
        while (1) {
            int pow_result = pow(p, q);
            if (pow_result > n)
                break;
            else if (pow_result == n) {
                sprintf(result, "%d %d", p, q);
                return result;
            } else {
                q ++;
            }
        }
    }

    sprintf(result, "%s", "No");
    return result;

}

int main()
{
    int test = 4913;
    char *result;

    result = super_prime_power(test);

    cout<<"result "<<result<<endl;
    free(result);
    return 0;
}

