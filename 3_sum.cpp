
/*
 * leetcode题目，给定一个数组，找出所有之和为0的三个元素
 
 * Given an array S of n integers, are there elements a,b,c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
• Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c) • Thesolutionsetmustnotcontainduplicatetriplets.
For example, given array S = {-1 0 1 2 -1 -4}.
A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

void three_sum(vector<int> in)
{
    unordered_map<int, int> nums;
    //sort(in.begin(), in.end());
    int sum = 0;
    int minus = 0;
    
    //先建立一个以数组元素值为key的hash表
    for(int i = 0; i < in.size(); i++) {
        nums[in[i]] = i + 1;
    }

    for(int i = 0; i < in.size(); i++) {
        for(int j = i + 1; j < in.size(); j++) {
            //cout<<"i "<<i<<" j "<<j<<endl;
            sum = in[i] + in[j];
            minus = 0 - sum;
            //cout<<"minus "<<minus<<" "<<nums[minus]<<endl;
            if (nums[minus]) //找到key
            {
                int key = nums[minus] - 1;
                if ((key > i) && (key > j)) {
                    cout<<"i "<<i<<" j "<<j<<" key "<<key<<endl;
                    cout<<"the numer: "<<in[i]<<" "<<in[j]<<" "<<in[key]<<endl;
                }
            }
        }
    }
}

int main()
{

    int n[] = {-1, 0, 1, 2, -1, -4} ;
    vector<int> test(n, n + 6);


    three_sum(test);

    return 0;
}


