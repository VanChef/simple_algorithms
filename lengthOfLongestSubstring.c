/*
leetcode题目，计算不包含重复字符的子字符串的最大长度，描述如下：

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(unsigned char* s) {

    int *chars = malloc(256 * sizeof(int));
    int *location = malloc(256 * sizeof(int));
    int start = 0;
    int end = 0;
    int length = 0;
    int max_len = 0;

    memset(chars, 0, 256);

    chars[s[end]] = 1; //标记该字符曾经出现过
    location[s[end]] = end; //保存该字符的位置
    length = 1;
    max_len = 1;

    end ++;

    while(1) {
        if (!s[end])
            break;

        if (chars[s[end]]) {
            start = location[s[end]] + 1;
            length = end - start + 1;
            chars[s[end]] = 1;
            location[s[end]] = end;
        } else {
            chars[s[end]] = 1;
            location[s[end]] = end;
            length ++;
            if (length > max_len)
                max_len = length;
        }
        printf("start %d,%c end %d,%c length %d\n", start, s[start], end, s[end], length);
        end ++;
    }
    free(chars);
    free(location);
    return max_len;
}


int main()
{
    int result = 0;
    unsigned char s[] = "abcabcbb";

    result = lengthOfLongestSubstring(s);
    printf("result %d\n", result);
}


