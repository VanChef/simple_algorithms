
/*

链接：https://www.nowcoder.com/questionTerminal/41cb7d4ed0254c69a06d596d89ad12a2
来源：牛客网

牛牛在研究他自己独创的平衡数，平衡数的定义是：将一个数分成左右两部分，分别成为两个新的数。
左右部分必须满足以下两点：
1，左边和右边至少存在一位。
2，左边的数每一位相乘如果等于右边的数每一位相乘，则这个数称为平衡数。
例如：1221这个数，分成12和21的话，1*2=2*1，则称1221为平衡数，再例如：1236这个数，可以分成123和1*2*3=6，所以1236也是平衡数。而1234无论怎样分也不满足平衡数。 
输入描述:

输入一个正整数（int范围内）。


输出描述:

如果该数是平衡数，输出 "YES", 否则输出 "NO"。
示例1
输入

1221
1234
输出

YES
NO
*/

#include <iostream>
#include <string>

using namespace std;

string is_balance_number(int n)
{
    char *tmp = (char *)malloc(128);
    memset(tmp, 0, 128);

    int i = 0;
    int len = 0;
    while(n) {
        tmp[len] = n % 10;
        n = n / 10;
        printf("%d\n", tmp[len]);
        len ++;
    }

    if (len <= 1)
        return "NO";

    int left = 0;
    int right = len - 1;

    int mul_left = tmp[left];
    int mul_right = tmp[right];

    cout<<"tmp "<<tmp<<"len "<<len<<endl;

    while(1)
    {
        cout<<"left "<<left<<" right "<<right<<endl;
        cout<<"mul_left "<<mul_left<<" mul_right "<<mul_right<<endl;

        if (mul_left > mul_right) {
            right --;
            mul_right *= tmp[right];
        } else if (mul_left < mul_right) {
            left ++;
            mul_left *= tmp[left];
        } else {
            cout<<"same, left "<<left<<" right "<<right<<endl;
            if (left + 1 == right)
                return "YES";
            left ++;
            right --;
            mul_right *= tmp[right];
            mul_left *= tmp[left];
        }
        if (left >= right)
            return "NO";
    }
}


int main()
{
    int test = 1236;
    cout<<"number "<<test<<" "<<is_balance_number(test)<<endl;
    return 0;
}


