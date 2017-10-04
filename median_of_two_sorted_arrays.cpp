
/*
leetcode题目，给定两个已排序数组，找出这两个数组所有元素的中位数
要求算法复杂度o(log(m+n))
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log(m + n)).
 */

#include <vector>
#include <iostream>

using namespace std;

int median_of_two_sorted_arrays(vector<int> &in1, vector<int> &in2)
{
    int ptr1 = in1.size() / 2;
    int ptr2 = in2.size() / 2;

    int step = min(ptr1 / 2, ptr2 / 2);

    while(1)
    {
        if (in1[ptr1] < in2[ptr2]) {
            ptr1 += step;
            ptr2 -= step;
        } else if (in1[ptr1] > in2[ptr2]) {
            ptr1 -= step;
            ptr2 += step;
        } else {
            return in1[ptr1];
        }

        if (step > 1) {
            step >>= 1;
            continue;
        } else {
            break;
        }
    }
    cout<<"end ptr1 "<<ptr1<<" end ptr2 "<<ptr2<<endl;
    return in1[ptr1];
}

int main()
{

    int a[] = {1, 2, 3, 4, 5,7,9,10,11,15,16,17};
    int b[] = {8,12,13,14,19,20};

    vector<int> in1(a, a + 12);
    vector<int> in2(b, b + 6);

    int result;

    result = median_of_two_sorted_arrays(in1, in2);

    cout<<"the result "<<result<<endl;

    return 0;
}


