

/*
 *
 *题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 *
 */



#include <iostream>     
using namespace std;     
    
int Min(int a, int b, int c)
{     
    int temp = (a < b ? a : b);     
    return (temp < c ? temp : c);     
}     
int FindUgly(int n) //  
{     
    int* ugly = new int[n];     
    ugly[0] = 1;     
    int index2 = 0;     
    int index3 = 0;     
    int index5 = 0;     
    int index = 1;     
    while (index < n)
    {  
        int val = Min(ugly[index2]*2, ugly[index3]*3, ugly[index5]*5); //竞争产生下一个丑数     
        if (val == ugly[index2]*2) //将产生这个丑数的index*向后挪一位；    
            ++index2;     
        if (val == ugly[index3]*3)   //这里不能用elseif，因为可能有两个最小值，这时都要挪动；  
            ++index3;     
        if (val == ugly[index5]*5)     
            ++index5;     
        ugly[index++] = val;     
    }     
/* 
    for (int i = 0; i < n; ++i)    
        cout << ugly[i] << endl;    
*/  
    int result = ugly[n-1];     
    delete[] ugly;     
    return result;     
}     
int main()     
{     
    int num;  
    cout << "input the number : " ;  
    cin >> num;  
    cout << FindUgly(num) << endl;  
    return 0;     
}
