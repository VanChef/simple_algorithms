/*
 * =====================================================================================
 *
 *       Filename:  permutation_and_combination.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2017 17:08:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>

//计算排列p (n, m) 即从n个数中取m个数并排列，共几种可能
int p(int n, int m) {
    int64_t ret = 1;
    int i;

    if (m == 1)
        return n;

    printf("n %d m %d\n", n, m);

    for (i = 1; i <= m; i ++) {
        ret *= (n - i + 1);
    }

    return ret;
}

//计算组合c (n, m) 即从n个数中取m个数，共几种可能
int c(int n, int m) {
    int64_t ret = 1;
    int i = 1;

    if (m == 0)
        return 1;

    if ((m == 1) || (m == n))
        return n;

    if (m > n / 2) {
        m = n - m;
    }

    std::list<int> tmp(m);
    std::list<int>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); it++) {
        *it = i;
        i ++;
    }

    printf("n %d m %d\n", n, m);

    for (i = 1; i <= m; i ++) {
        ret *= (n - i + 1);
        if (tmp.empty())
            continue;

        for(it = tmp.begin(); it != tmp.end(); it++) {
            if ((ret % *it)==0) {
                ret /= *it;
                printf("it %d\n", *it);
                tmp.erase(it);
            }
        }
    }

    return ret;
}

int main() {
    int n = 100;
    int num_one = n;
    int num_two = 0;

    int i, j, k;
    int ret = 0;
    int tmp = n;

    printf("p %d\n", p(6, 4));
    printf("c %d\n", c(6, 4));

    return 0L;
}


