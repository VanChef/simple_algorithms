

#include <vector>
#include <iostream>


using namespace std;

// 编译命令：g++ test_rvo.cpp -O3 -o test_rvo
// 如果用 std::vector<int>& foo() 声明函数，会产生崩溃

std::vector<int> foo() {
    std::vector<int> tmp = {1, 2, 3, 4};

    for (auto i : tmp) {
        cout<<i<<" addr "<<&i<<' '<<endl;
    }
    cout<<&tmp<<endl;

    return tmp;
}

int main() {


    auto aaa = foo();

    for (auto i : aaa) {
        cout<<i<<" addr "<<&i<<' '<<endl;
    }

}

