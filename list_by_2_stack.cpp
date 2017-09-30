/*
 * 常见题目，用两个栈来实现一个队列
 *
 * */

#include <stack>
#include <iostream>


using namespace std;

class mylist {

    public:
        mylist() {
        }

    private:
        stack<int> mystack1;
        stack<int> mystack2;

    public:
        void add_tail(int value) {
            mystack1.push(value);
        }
        int get_head() {
            while(!mystack1.empty()) {
                mystack2.push(mystack1.top());
                mystack1.pop();
            }
            int value = mystack2.top();
            mystack2.pop();
            while(!mystack2.empty()) {
                mystack1.push(mystack2.top());
                mystack2.pop();
            }
            return value;
        }
};

int main() {

    class mylist t;

    t.add_tail(1);
    t.add_tail(2);
    t.add_tail(3);
    
    cout<<"head "<<t.get_head()<<endl;

    return 0L;
}


