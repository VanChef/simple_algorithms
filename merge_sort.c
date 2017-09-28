
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *out, int size_out, int *in1, int size1, int *in2, int size2)
{
    int value1, value2;
    int ptr1 = 0, ptr2 = 0, out_ptr = 0;

    value1 = in1[ptr1];
    value2 = in2[ptr2];

    while(1) {
        printf("value1 %d, value2 %d\n", value1, value2);
        if (value1 < value2) {
            out[out_ptr ++] = value1;
            ptr1 ++;
            if (ptr1 >= size1) {
                break;
            } else {
                value1 = in1[ptr1];
            }
        } else {
            ptr2 ++;
            out[out_ptr ++] = value2;
            if (ptr2 >= size2) {
                break;
            } else {
                value2 = in2[ptr2];
            }
        }
    }

    printf("%d, %d, %d, %d, %d\n", ptr1, ptr2, size1, size2, out_ptr);

    if (ptr1 >= size1) {
        printf("out_ptr %d, ptr2 %d, size2 - ptr2 %d\n", out_ptr, ptr2, size2 - ptr2);
        memcpy(&out[out_ptr], &in2[ptr2], (size2 - ptr2)*sizeof(int));
    }
    if (ptr2 >= size2) {
        memcpy(&out[out_ptr], &in1[ptr1], (size1 - ptr1)*sizeof(int));
    }
}


int main()
{
    int i;
    int in1[] = {1,4,5,6,7,9};
    int in2[] = {3,8,10,11,18,20};
    int *out = malloc(sizeof(int)*12);


    merge_sort(out, 12, in1, 6, in2, 6);

    printf("out value \n");
    for (i = 0; i < 12; i ++) {
        printf("%d, ", out[i]);
    }
    printf("\n");
}

