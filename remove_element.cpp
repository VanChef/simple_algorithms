/*
leetcode题目，删除数组中值为target的元素，返回新的长度

 * 2.1.11 Remove Element
  
Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn’t matter what you leave beyond the new length.
 *
 *
 */

#include <vector>
#include <iostream>

using namespace std;

int remove_element(vector<int> &in, int target)
{
    int index = 0;
    int i;

    for (i = 0; i < in.size(); i++) 
    {
        if (in[i] != target) {
            in[index++] = in[i];
        }
    }
    return index;
}

int main()
{
    int n[] = {1, 3, 5, 6, 4, 7, 5, 3, 4, 5};
    vector<int> test(n, n + 10);

    int new_len = remove_element(test, 5);

    for (int i = 0; i < new_len; i ++) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
}

