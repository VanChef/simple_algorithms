/* 
 * 《编程之美》上的一道题
 * 给定一个正整数，判断该从1到正整数的数列中，1出现的个数
 * 如给定12，则数列1，2，3，4，5，6，7，8，9，10，11，12，1出现的个数为5
 * 为提高效率，采用递归的方法 */


#include <stdio.h>

int num_of_ones(int num) {


    int i,j,k;
    int ret = 0;
    int power = 1;

    int nums[128];

    printf("input %d\n", num);

    i = 0;
    k = num;
    while(1) {

        j = k % 10;   //
        nums[i] = j;
        k = k / 10;

        if (k == 0)
            break;

        i ++;
        power = power * 10;
    }

    printf("i %d, power %d, nums[i] %d\n", i, power, nums[i]);
    if (i == 0) {
        if (num == 0)
            return 0;
        else
            return 1;
    }

    ret = 0;
    if (nums[i] > 1) {
        for (j = i; j >= 0; j--) {
            if (j == i)
                ret += power;
            else
                ret += power / 10 * nums[i];
        }
    }
    else {
        ret += power / 10 * i;
        ret += (num - power * nums[i] + 1);
    }

    printf("ret %d \n", ret);

    return (ret + num_of_ones(num - power * nums[i]));
}

int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);

    int result;


    result = num_of_ones(input);

    printf("result %d\n", result);
    
    return 0L;
}

