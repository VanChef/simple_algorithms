
/*
 * 常见题目
 *
 * 输入一个链表，输出该链表中倒数第k个结点。
 *
 *
 */

#include <list>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    int FindKthToTail(ListNode* pListHead, unsigned int k) {
        int current_num = 0;
        list<int> mylist;

        while(pListHead) {
            if (current_num >= k) {
                int current_top = mylist.front();
                mylist.pop_front();
                cout<<"pop front "<<current_top<<endl;
            }

            mylist.push_back(pListHead->val);
            current_num ++;

            cout<<"current_num "<<current_num<<endl;

            pListHead = pListHead->next;
        }
        cout<<"value "<<mylist.front()<<endl;

        return mylist.front();
    }
};

int main()
{
    class Solution t;
    struct ListNode *mylist;
    struct ListNode *p;

    p = mylist = new ListNode(1);
    mylist->next = new ListNode(2);
    mylist->next->next = new ListNode(3);
    mylist->next->next->next = new ListNode(4);
    mylist->next->next->next->next = new ListNode(5);
    mylist->next->next->next->next->next = new ListNode(6);

    t.FindKthToTail(p, 2);

    return 0;
}

