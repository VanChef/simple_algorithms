/*
 * =====================================================================================
 *
 *       Filename:  btree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月05日 11时03分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct tree  
{
    char data;
    struct tree * lchild;
    struct tree * rchild;
    unsigned int isOut;
}TreeNode,*Tree; 


void CreateTree(Tree &t)  
{
    char ch;
    cout<<"please input tree node value, # for NULL, in pre order"<<endl;
    cin>>ch;
    if (ch == '#')
        t = NULL;
    else
    {
        t = (Tree)malloc(sizeof(TreeNode));  
        t->data = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        if (!t)
        {
            cout<<"malloc error!"<<endl;  
            return;
        }
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}

void PreOrder(Tree t)
{
    stack<Tree> mystack;

    while (t || !mystack.empty())
    {
        if (t)
        {
            cout<<t->data<<endl;
            mystack.push(t);
            t = t->lchild;
        }
        else
        {
            Tree tmp;

            tmp = mystack.top();
            t = tmp->rchild;
            mystack.pop();
        }
    }
    return;
}

void MidOrder(Tree t)
{
    stack<Tree> mystack;

    while (t || !mystack.empty())
    {
        if (t)
        {
            mystack.push(t);
            t = t->lchild;
        }
        else
        {
            Tree tmp;

            tmp = mystack.top();
            cout << tmp->data << endl;

            t = tmp->rchild;
            mystack.pop();
        }
    }
    return;
}

//
void PostOrder(Tree t)  
{  
    t->isOut = 0;  
    Tree p = t;  
    list<Tree> mylist;
    stack<Tree> mystack;
  
    while (p || !mylist.empty())  
    {  
        if (p)  
        {  
            if (p->isOut)  
            {//l/r child are already output
                p = mystack.top();
                cout<<p->data<<endl;
                mystack.pop();

                if (!mystack.empty())  
                    p = mystack.top(); //get parent
                else  
                    p = NULL;  
            }  
            else  
            {      
                if ((p->lchild) && (p->lchild->isOut == 1))  
                {//if there is a left child, and left is already output, means this node is pushed, goto right child 
                    p->isOut = 1;  
                    p = p->rchild;     
                }  
                else  
                {  
                    mystack.push(p);
                    p = p->lchild;  
                }            
            }  
        }
        else  
        {
            if (!mystack.empty())  
                p = mystack.top();
            else  
                p = NULL;  
  
            if (p->rchild)  
            {  
                p = p->rchild;  
            }  
            else  
            {  
                p = mystack.top();
                cout<<p->data<<endl;
                mystack.pop();

                p->isOut = 1;  
                if (!mystack.empty())  
                {  
                    p = mystack.top();
                    if (p->lchild == NULL)  
                        p->isOut = 1; //right child is output, so set parent isOUt to 1
                }  
                else  
                    p = NULL;
            }          
        }
    }
}

void PostOrder2(Tree t)    //
{
    Tree temp;
    stack<Tree> mystack;

    while (t!=NULL || !mystack.empty())
    {
        while (t!=NULL)              //沿左子树一直往下搜索，依次压栈，直至出现没有左子树的结点
        {
            t->isOut = true;
            mystack.push(t);
            t = t->lchild;
        }
        if (!mystack.empty())
        {
            temp = mystack.top();       //栈顶元素弹出
            mystack.pop();
            if (temp->isOut==true)     //表示是第一次出现在栈顶，并将标志位赋值为不是第一次出现
            {
                temp->isOut = false;    //再压回栈，并访问其右子树
                mystack.push(temp);
                t = temp->rchild;
            }
            else                        //第二次出现在栈顶
            {
                cout<<temp->data<<endl;
                t = NULL;
            }
        }
    }
}

int main()
{
    Tree t;
    CreateTree(t);
    
    cout<<"mid order:"<<endl;
    MidOrder(t);

    cout<<"pre order:"<<endl;
    PreOrder(t);
    
    cout<<"post order:"<<endl;
    PostOrder2(t);
    return 0L;
}



