
/*

给定一个数组，大小为98，里面的元素均为在[0, 99]，且无重复，找出缺失的两个元素值。
要求：不能申请额外的空间，时间复杂度为O(N)

*/

#include <vector>
#include <iostream>

using namespace std;

void swap(int& in1, int& in2)
{
    int tmp;
    tmp = in1;
    in1 = in2;
    in2 = tmp;
}


void find_missing(int* in, int size)
{
    for(int i = 0; i < size; i++)
    {
        while (in[i] != i) {
            if (in[i] >= size || in[i] < 0)
                break;
            cout<<"i "<<i<<" in[i]"<<in[i]<<endl;
            int tmp = in[i];
            in[i] = in[tmp];
            in[tmp] = tmp;
        }
    }

    for(int i = 0; i < size; i++)
    {
        if (in[i] != i)
            cout<<"missing "<<i<<endl;
    }

}

int main()
{
    int test[98];

    for (int i = 0; i < 98; i ++)
        test[i] = i;

    test[9] = 99; 
    test[10] = 98; 

    swap(test[9], test[0]);
    swap(test[10], test[5]);


    for (int i = 0; i < 98; i ++)
        cout<<"test["<<i<<"]"<<"="<<test[i]<<endl;

    find_missing(test, 98);

    return 0;
}


