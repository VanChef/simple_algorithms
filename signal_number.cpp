
/*

leetcode上一道题   

2.1.24 Single Number II
  
Given an array of integers, every element appears three times except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

自己没想出来
参考别人的代码吧

用二进制模拟“三进制”，当二进制某一位上出现三次1时，将该位清零

*/
#include <vector>
#include <iostream>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int one = 0, two = 0, three = 0;
    for (auto i : nums) {
        two |= (one & i);
        one ^= i;
        three = ~(one & two);
        one &= three;
        two &= three;
    }
    return one;
}

//这个解法更容易理解一些
int singleNumber2(vector<int>& nums)
{
    const int W = sizeof(int) * 8;
    int count[W];//每个count[i]表示二进制一位
    memset(count, 0, W * sizeof(int));
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < W; j++) {
            count[j] += (nums[i] >> j) & 1;
            count[j] %= 3;
        }
    }
    int result = 0;
    for (int i = 0; i < W; i++) {
        result += (count[i] << i);
    }
    return result;
}

int main()
{
    int test[] = {10 ,5,4,10,5,4,10,5,4,9};
    vector<int> t(test, test + 10);

    int result = singleNumber2(t);

    cout<<"result "<<result<<endl;

    return 0;
}

