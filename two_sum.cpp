

/*
 *
 * leetcode题目，给定一个数组和一个整数，找出数组中的两个元素，使这两个元素之和等于给定整数
 * Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution. Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 *
 */


#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int> &in, int target)
{
    unordered_map<int, bool> used;
    vector<int> result;

    for (auto i : in) {
        used[i] = true;
    }
    for (auto i : in) {
        int minus = target - i;
        if (used[minus]) {
            result.push_back(i);
            result.push_back(minus);
            return result;
        }
    }
    result.clear();
    return result;
}

int main()
{
    vector<int> result;

    int n[] = {2, 7, 11, 15} ;
    vector<int> test(n, n + 4) ;              //将数组n的前5个元素作为向量a的初值

    for (auto i : test) {
        cout<<i<<endl;
    }


    result = two_sum(test, 9);

    for (auto i : result) {
        cout<<i<<endl;
    }

    return 0;
}

