
/*
 *左程云书上的题，给定两个有序链表，打印这两个链表的共有元素
 *
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

void print_same_value_in_two_sorted_array(int *a, int size1, int *b, int size2)
{
    int i = 0, j = 0;

    while(1) {

        if (*(a + i) > *(b + j)) {
            j ++;
        } else if (*(a + i) < *(b + j)) {
            i ++;
        } else {
            printf("%d, ", *(a + i));
            i ++;
            j ++;
        }

        if ((i > size1 - 1) || (j > size2 - 1))
            break;
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    print_same_value_in_two_sorted_array(a, 10, b, 10);

    return 0;
}


