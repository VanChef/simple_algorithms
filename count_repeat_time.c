
/*
 *计算数字重复出现的次数，如给定两个数组，都包含a-z，A-Z的英文字母，编程给出两个数组中都出现的字母
 *
 *
 * */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void repeat_letter(char *a, char *b, int a_len, int b_len)
{
    char *letter_a = malloc(26 * 2);
    char *letter_b = malloc(26 * 2);
    int i = 0;

    memset(letter_a, 0, 26);
    memset(letter_b, 0, 26);

    for (i = 0; i < a_len; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            letter_a[a[i] - 'a'] = 1;
        }
        if (a[i] >= 'A' && a[i] <= 'Z') {
            letter_a[a[i] - 'A' + 26] = 1;
        }
    }

    for (i = 0; i < b_len; i++) {
        if (b[i] >= 'a' && b[i] <= 'z') {
            letter_b[b[i] - 'a'] = 1;
        }
        if (b[i] >= 'A' && b[i] <= 'Z') {
            letter_b[b[i] - 'A' + 26] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (letter_a[i] == 1 && letter_b[i] == 1) {
            printf("%c\n", 'a' + i);
        }
    }
    for (i = 0; i < 26; i++) {
        if (letter_a[i + 26] == 1 && letter_b[i + 26] == 1) {
            printf("%c\n", 'A' + i);
        }
    }

    free(letter_a);
    free(letter_b);

    return;
}


int main()
{
    char test_a[10] = {'a', 'y', 'R', 'E', 'w', 'q', 'c', 'Q', 'x'}; 
    char test_b[10] = {'t', 'y', 'e', 'o', 'O', 's', 'S', 'Q', 'x'}; 

    repeat_letter(test_a, test_b, 10, 10);
    return 0L;
}



