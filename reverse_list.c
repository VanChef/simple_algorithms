
/*
 * 常见题目：
 * 反转一个单链表
 *
 * */

#include <stdio.h>
#include <stdlib.h>


struct List {
    int value;
    struct List* next;
};

struct List *reverse_list(struct List *p)
{
    if (!p)
        return NULL;

    struct List *before = NULL;
    struct List *current = p;
    struct List *after = p->next;

    while(1) {
        if (!current->next)
            break;
        current->next = before;
        before = current;
        current = after;
        after = current->next;
    }
    current->next = before;

    return current;
}

void print_list(struct List *p)
{
    printf("\n");
    while (p) {
        printf("%d, ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    struct List *in = malloc(sizeof(struct List));
    struct List *out;
    in->value = 9;
    in->next = malloc(sizeof(struct List));
    in->next->value = 8;
    in->next->next = malloc(sizeof(struct List));
    in->next->next->value = 7;
    in->next->next->next = NULL;

    print_list(in);

    out = reverse_list(in);

    print_list(out);

    return 0L;
}




