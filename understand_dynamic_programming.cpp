/*

http://www.hawstein.com/posts/dp-novice-to-advanced.html

问题：如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？

用d(i)表示凑够i元需要的最少硬币数量

状态转移方程：d(i) = min{ d(i - v[j]) + 1 }
其中i - v[j] >= 0，v[j]表示第j个硬币的面值

*/

#include <iostream>

using namespace std;

#define COIN_NUM        3
static int coin_value[COIN_NUM] = {1, 3, 5}; 

int min_coin(int total_value)
{
    if (total_value == 0)
        return 0;

    int coin_count_min = 0;
    for (int i = 0; i < COIN_NUM; i ++) {
        if (coin_value[i] <= total_value) {
            int tmp = min_coin(total_value - coin_value[i]) + 1;
            if (tmp < coin_count_min || coin_count_min == 0)
                coin_count_min = tmp;
        }
    }

    cout<<"total_value "<<total_value<<" coin_count_min "<<coin_count_min<<endl;

    return coin_count_min;
}

int main()
{
    int result;

    result = min_coin(11);

    cout<<"result "<<result<<endl;

    return 0;
}


