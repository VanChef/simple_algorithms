
/*
 * 剑指offer上一道题
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 *
 */


/*
 *
 * 自己没想出来。。。
 * 这里附上别人的代码和思路，多加学习
 * 转载：http://blog.csdn.net/wuzhekai1985/article/details/6704902
 *
 *
 *问题描述：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。例如输入数组{32,  321}，则输出这两个能排成的最小数字32132。请给出解决问题的算法，并证明该算法。
      思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。如果ab < ba，则a < b；如果ab > ba，则a > b；如果ab = ba，则a = b。比较函数的定义是本解决方案的关键。
      证明：为什么这样排个序就可以了呢？简单证明一下。根据算法，如果a < b，那么a排在b前面，否则b排在a前面。可利用反证法，假设排成的最小数字为xxxxxx，并且至少存在一对字符串满足这个关系：a > b，但是在组成的数字中a排在b前面。根据a和b出现的位置，分三种情况考虑：
      （1）xxxxab，用ba代替ab可以得到xxxxba，这个数字是小于xxxxab，与假设矛盾。因此排成的最小数字中，不存在上述假设的关系。
      （2）abxxxx，用ba代替ab可以得到baxxxx，这个数字是小于abxxxx，与假设矛盾。因此排成的最小数字中，不存在上述假设的关系。
      （3）axxxxb，这一步证明麻烦了一点。可以将中间部分看成一个整体ayb，则有ay < ya，yb < by成立。将ay和by表示成10进制数字形式，则有下述关系式，这里a，y，b的位数分别为n，m，k。
        关系1： ay < ya => a * 10^m + y < y * 10^n + a => a * 10^m - a < y * 10^n - y => a( 10^m - 1)/( 10^n - 1) < y
        关系2： yb < by => y * 10^k + b < b * 10^m + y => y * 10^k - y < b * 10^m - b => y < b( 10^m -1)/( 10^k -1) 
        关系3： a( 10^m - 1)/( 10^n - 1) < y < b( 10^m -1)/( 10^k -1)  => a/( 10^n - 1)< b/( 10^k -1) => a*10^k - a < b * 10^n - b =>a*10^k + b < b * 10^n + a => a < b
       这与假设a > b矛盾。因此排成的最小数字中，不存在上述假设的关系。
       综上所述，得出假设不成立，从而得出结论：对于排成的最小数字，不存在满足下述关系的一对字符串：a > b，但是在组成的数字中a出现在b的前面。从而得出算法是正确的。
 *
 */

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;


//重新定义比较函数对象  
struct compare  
{  
    bool operator() (const string &src1, const string &src2)  
    {  
        string s1 = src1 + src2;  
        string s2 = src2 + src1;  
        return s1 < s2;   //升序排列，如果改为s1 > s2则为逆序排列  
    }  
};  
//函数功能 ： 把数组排成最小的数  
//函数参数 ： pArray为数组,num为数组元素个数    
//返回值 ：   无  
void ComArrayMin(int *pArray, int num)  
{  
    int i;  
    string *pStrArray = new string[num];  
  
    for(i = 0; i < num; i++) //将数字转换为字符串  
    {     
        stringstream stream;  
        stream<<pArray[i];  
        stream>>pStrArray[i];  
    }  
  
    sort(pStrArray, pStrArray + num, compare()); //字符串数组排序  
  
    for(i = 0; i < num; i++) //打印字符串数组  
        cout<<pStrArray[i];  
    cout<<endl;  
  
    delete [] pStrArray;  
}  


int main()
{
    int test[] = {3, 32, 321};

    ComArrayMin(test, 3);
    return 0;
}


