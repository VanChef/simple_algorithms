
/*
题目：给定一个float型数组，求子数组乘积的最大值。其中，子数组定义为从原数组中取出一段连续元素组成的数组

解析：此题可以运用动态规划解决

设f[i]表示以i为结尾的最大值，g[i]表示以i结尾的最小值，那么

f[i+1] = max{f[i]*arr[i+1], g[i]*arr[i+1],arr[i+1]} ,只有这三种情况。

考虑到f[i]，g[i]只和i-1有关，那么可以用局部变量即可搞定，而不用使用数组。

*/

#include <iostream>
#include <vector>

using namespace std;

double maxProduct(vector<double> arr)
{
    if (arr.size() == 0)
        return 0;
    double minVal = arr[0];
    double maxVal = arr[0];
    double rtn = arr[0];

    double tmpMax = 0;
    double tmpMin = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        //cout << "max\t" << maxVal << endl;
        //cout << "min\t" << minVal << endl;
        tmpMax = max(maxVal * arr[i], minVal * arr[i]);
        tmpMin = min(maxVal * arr[i], minVal * arr[i]);

        maxVal = max(tmpMax, arr[i]);
        minVal = min(tmpMin, arr[i]);

        rtn = max(rtn, maxVal);
    }
    return rtn;
}


int main()
{
    double arr[] = {-2.5, 4, 0, 3, 0.5, 8, -1};
    vector<double> vect_double(arr, arr + 7);

    cout<<"result "<<maxProduct(vect_double);

    return 0;
}


