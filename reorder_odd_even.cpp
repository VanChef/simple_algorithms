
/*
剑指offer上一道题

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

加一个限定条件：不允许使用额外的存储空间

解题技巧：这种题目一定要想清楚细节，找准一个方法，然后可以通过具体的实例确定写法
对于这道题，思路就是遇到一个奇数的时候，把他之前所有的偶数后移一位，在把这个奇数挪到偶数的头
这样就分成两种情况，遍历到该奇数时，之前有偶数/之前没有偶数
用event_start表示之前偶数的起始下标，
如果之前有偶数，那么则需要移动数组，由于最前面插入了一个奇数，event_start应该++，
如果之前没有偶数，那么even_start = i + 1用来和下一个遍历下标(i)保持一致，

*/

#include <vector>
#include <iostream>

using namespace std;

void reorder_odd_even(vector<int> &in)
{
    int even_start = 0;

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] & 1)
        {
            int tmp = in[i];
            for (int j = i; j > even_start; j --)
            {
                in[j] = in[j - 1];
            }
            in[even_start] = tmp;
            cout<<"i "<<i<<" even_start "<<even_start<<endl;
            if (in[i] & 1)
                even_start = i + 1;
            else
                even_start ++;
        }
    }
}

#if 0
/*
想到一种更加清晰、直观，并且效率更高的做法：
维护4个下标指针：

odd_start
odd_end;
even_start
even_end;

初始值都赋为0，遍历数组，如果是偶数则odd_end++，奇数则even_end++
同时判断当前下标是否和odd_end或even_end连续，如果不连续，则需要将odd_start到odd_end和even_start到even_end直接的数交换

*/

void exchange(vector<int> &in, int start1, int end1, int start2, int end2)
{
    
}

void reorder_odd_even2(vector<int> &in)
{
    int odd_start = 0, odd_end = 0, even_start = 0, even_end = 0;
    bool first_odd = false, first_even = false;

    for(int i = 0; i < in.size(); i++) {
        if (in[i] & 1) {
            if (!first_odd) {
                odd_start = i;
                odd_end = i;
            } else {
                if (i != odd_end + 1) {
                    if (first_even) { //exchange here
                    
                        odd_start = odd_end = even_start = even_end = i;
                        first_even = false;
                        first_odd = false;
                    }
                } else {
                    odd_end ++;
                }
            }
        } else {
            if (!first_even) {
                even_start = i;
                even_end = i;
            } else {
                if (i != even_end + 1) { 
                    if (first_odd) { //exchange here
                    
                        odd_start = odd_end = even_start = even_end = i;
                        first_even = false;
                        first_odd = false;
                    }
                } else {
                    even_end ++;
                }
            }
        }
    }
}
#endif

int main()
{
    int test[] = {19, 4, 5, 6, 3, 2, 55, 54, 77, 90};

    vector<int> t(test, test + 10);

    reorder_odd_even(t);

    for (int i = 0; i < t.size(); i++) {
        cout<<t[i]<<" "<<endl;
    }

    return 0;
}


