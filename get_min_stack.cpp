/*
 *数据结构题目，设计一个带有获取当前栈中最小值方法getMin的栈
 *要求getMin方法复杂度为O(1)
 *
 *解题思路是维护一另一个栈mystack_min，栈顶始终是当前栈的最小值，当前栈push的时候
 *如果小于当前的最小值，则push最新的最小值，否则重复mystack_min栈顶元素
 *
 * */

#include <stack>
#include <iostream>


using namespace std;


class getMinStack {

private:
    stack<int> mystack;
    stack<int> mystack_min;

public:
    int getMin() {
        return mystack_min.top();
    };

    void push(int value) {
        mystack.push(value);
        if (mystack_min.empty())
            mystack_min.push(value);
        else {
            if (value < mystack_min.top())
                mystack_min.push(value);
            else
                mystack_min.push(mystack_min.top());
        }
    };

    int pop() {
        int pop_value;
        pop_value = mystack.top();
        mystack.pop();
        mystack_min.pop();
        return pop_value;
    };
};

int main()
{
    class getMinStack test_stack;

    test_stack.push(20);
    test_stack.push(8);
    test_stack.push(3);
    test_stack.push(2);
    test_stack.push(9);

    cout<<"current min value is "<<test_stack.getMin()<<endl;

    test_stack.pop();
    test_stack.pop();

    cout<<"current min value is "<<test_stack.getMin()<<endl;

    test_stack.push(1);

    cout<<"current min value is "<<test_stack.getMin()<<endl;
    return 0L;
}


