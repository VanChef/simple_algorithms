
/*
 * 为理解递归，网上找的一些递归题目
 */


/*
 *编写一个方法用于验证指定的字符串是否为反转字符，返回true和false。请用递归算法实现。（反转字符串样式为"abcdedcba"）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_symmetry_string(char *in, int len)
{
    printf("%s, %d\n", in, len);
    if (len <= 1)
        return 1;

    return (in[0] != in[len - 1]) ? 0 : is_symmetry_string(in + 1, len - 2);
}

/*
一个射击运动员打靶,靶一共有10环,连开10枪打中90环的可能行有多少种?

*/
#if 0
int shoot(int total, int num)
{
    int i;
    int result = 0;

    for (i = 0; i < 10; i++) {
        result = result + shoot(total - i, num - 1);
    }

    return shoot(total - 10, num - 1) + 10;
}
#endif

int main()
{
    char a[] = "abcdefedcba";

    printf("result %d\n", is_symmetry_string(a, strlen(a)));

    return 0;
}



