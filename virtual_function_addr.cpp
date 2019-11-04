
#include <iostream>

using namespace std;

class Base {
public:
virtual void f() { cout << "Base::f" << endl; }
virtual void g() { cout << "Base::g" << endl; }
virtual void h() { cout << "Base::h" << endl; }
};
typedef void(*Fun)(void);
int main() {

    Base b;
    Fun pFun = NULL;

    cout<< "虚函数表地址：" << (int*)(&b) << endl;

    cout<< "虚函数表 — 第一个函数地址：" << (int64_t*)*(int64_t*)(&b) << endl;

    // Invoke the first virtual function
    pFun = (Fun)*((int64_t*)*(int64_t*)(&b));

    pFun();

    return 0;
}

