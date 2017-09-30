/*
 * 题目：给定一个字符串，反转字符串中的单词，
 *
 * */

#include <stack>
#include <iostream>

using namespace std;

int is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

void reverse_word(char *in)
{
    int start = 0;
    int end = 0;
    stack<char> my_stack;

    while (1) {
        if (is_letter(in[start])) {
            end = start;
            my_stack.push(in[end]);
            end ++;
            while (1) {
                if (is_letter(in[end])) {
                    my_stack.push(in[end]);
                    end ++;
                } else {
                    break;
                }
            }
            while(!my_stack.empty()) {
                in[start] = my_stack.top();
                my_stack.pop();
                start ++;
            }
            start ++;//move to next un-letter char

        } else {
            if (!in[start])
                break;
            start ++;
            end ++;
        }
    
    }
}

int main()
{
    char a[100] = "Hello, world!";

    snprintf(a, 100, "Hello, world!");
    a[99] = 0;

    reverse_word(a);

    printf("result: %s", a);

    return 0L;
}

