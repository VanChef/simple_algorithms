
/*
一道常见的面试题，进制转换，

例如：输入一个int型十进制数，以字符串形式输出一个十二进制数

*/

#include <iostream>

void reverse_string(char *s)
{
    int ptr_start = 0;
    int ptr_end = strlen(s) - 1;
    char tmp;

    while(ptr_start <= ptr_end - 1) {
        //swap
        tmp = s[ptr_start];
        s[ptr_start] = s[ptr_end];
        s[ptr_end] = tmp;

        ptr_start ++;
        ptr_end --;
    }
}

char *convert(int in, int jinzhi)
{
    char *result = (char *)malloc(64);
    memset(result, 0, 64);

    int i = 0;
    while(in)
    {
        sprintf(result + i, "%x", in % jinzhi);
        in = in / jinzhi;
        i ++;
    }

    reverse_string(result);
    return result;
}


int main()
{
    char* result = convert(200, 16);

    printf("result: %s\n", result);

    return 0;
}

