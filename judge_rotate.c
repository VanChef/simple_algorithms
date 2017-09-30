/*
 *
 * 常见题目：判断两个字符串是否互为旋转串
 *
 * 旋转串的定义为：给定一个字符串，将其前面的若干个字符依次移动到字符串末尾，即形成一个改字符串的旋转串
 *
 * 例如：给定字符串abcdefg, 则bcdefga, cdefgab都是其旋转串
 *
 * 简单的搜索可以解决该问题，如下代码所示，但如果要最优解，又要用到KMP算法，见kmp.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge_rotate(char *in1, char* in2)
{
    int len1 = strlen(in1);
    int len2 = strlen(in2);
    int i, start, j;

    if (len1 != len2)
        return 0;

    for (start = 0; start < len2; start ++)
    {
        j = 0;
        for (i = start; i < start + len1; i++) {
            i = i % len1;
            printf("i %d \n", i);
            if(in1[i]!=in2[j])
                break;
            j++;
        }
        printf("j %d, start %d, len1 %d\n", j, start, len1);
        if (j == len1)
            return 1;
    }
    return 0;
}

int main()
{
    char a[7] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
    char b[7] = {'c', 'd', 'e', 'f', 'a', 'b', '\0'};

    int result;

    result = judge_rotate(a, b);
    
    printf("result %d\n", result);

    return 0L;
}

