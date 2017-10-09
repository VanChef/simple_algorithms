
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

int main()
{
    int test[] = {10 ,5,4,10,5,4,10,5,4,9};
    vector<int> t(test, test + 10);

    int result = singleNumber(t);

    cout<<"result "<<result<<endl;

    return 0;
}

