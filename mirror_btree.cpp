
/*

题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5


*/

#include <iostream>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {

        if (pRoot->left || pRoot->right) {
            struct TreeNode *p;
            p = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = p;

            Mirror(p->left);
            Mirror(p->right);
        } 
    }
};

int main()
{
    struct TreeNode *btree;
    class Solution t;

    btree = new TreeNode(8);
    btree->left = new TreeNode(6);
    btree->right = new TreeNode(10);

    btree->left->left = new TreeNode(5);
    btree->left->right = new TreeNode(7);


    btree->right->left = new TreeNode(9);
    btree->right->right = new TreeNode(11);

    t.Mirror(btree);


    return 0;
}
