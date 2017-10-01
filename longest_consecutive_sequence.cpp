
/*
leetcode题目，给定一个无序int数组，找出最大连续的连续整数个数

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
 *
 */

//编译
/*
g++ -std=c++11 longest_consecutive_sequence.cpp -o longest_consecutive_sequence
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        int longestConsecutive(const vector<int> &nums) {
            unordered_map<int, bool> used;
            //初始化
            for (auto i : nums) 
                used[i] = false;
            int longest = 0;
            for (auto i : nums) {
                if (used[i]) continue;
                int length = 1;
                used[i] = true;
                for (int j = i + 1; used.find(j) != used.end(); ++j) {
                    used[j] = true;
                    ++length; }
                for (int j = i - 1; used.find(j) != used.end(); --j) {
                    used[j] = true;
                    ++length; }
                longest = max(longest, length);
            }
            return longest;
        }
};

int main()
{
    class Solution s;
    int ret;
    vector<int> input;

    input.push_back(100);
    input.push_back(4);
    input.push_back(200);
    input.push_back(1);
    input.push_back(3);
    input.push_back(2);

    ret = s.longestConsecutive(input);

    cout<<"result "<<ret<<endl;

    return 0L;

}


