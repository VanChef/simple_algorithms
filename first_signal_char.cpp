/*

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符

*/

#include <iostream>

using namespace std;

char first_signal_char(char *s)
{
    int *chars = new int[256];
    memset(chars, 0, sizeof(int)*256);

    char *p = s;
    while(*p) {
        chars[*p]++;
        p ++;
        cout<<"p "<<*p<<endl;
    }

    p = s;
    char ret;
    int found = 0;
    while(*p) {
        if(chars[*p] == 1) {
            ret = *p;
            found = 1;
            break;
        }
        p++;
    }

    return found == 1 ? *p : '#'; 
}

int main()
{
    char *s = (char *)malloc(1024);
    memset(s, 0, 1024);
    snprintf(s, 1024, "%s", "google");
    s[6] = 0;

    char ret = first_signal_char(s);
    cout<<"result "<<ret<<endl;

    return 0;
}

