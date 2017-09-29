
/*
leetcode上一道题，描述如下：
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int number1 = l1->val;
    int number2 = l2->val;
    int sum;
    struct ListNode* result = malloc(sizeof(struct ListNode)); 
    struct ListNode* org = result; 
    int power = 10;

    struct ListNode* p = l1->next;

    while(p) {
        number1 += p->val * power;
        power *= 10;
        p = p->next;
    }

    p = l2->next;
    power = 10;
    while(p) {
        number2 += p->val * power;
        power *= 10;
        p = p->next;
    }

    sum = number1 + number2;
    printf("number1 %d, number2 %d, sum %d\n", number1, number2, sum);

    while(1) {
        result->val = sum % 10;
        if (sum / 10) {
            result = result->next = malloc(sizeof(struct ListNode));
            memset(result, 0, sizeof(struct ListNode));
            sum /= 10;
        } else
            break;
    }
    return org;
}

int main()
{
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* result;

    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = 0;

    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = 0;

    result = addTwoNumbers(l1, l2);

    while(result) {
        printf("%d, ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0L;
}

