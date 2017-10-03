
/*
 * 常见算法题，求二叉树的深度，采用递归的方法
 * 需要理解递归的含义
 *
 * 可以参考简书上这篇文章
 * http://www.jianshu.com/p/4db970d8ddc1
 *
递归：你打开面前这扇门，看到屋里面还有一扇门（这门可能跟前面打开的门一样大小（静），也可能门小了些（动）），你走过去，发现手中的钥匙还可以打开它，你推开门，发现里面还有一扇门，你继续打开，。。。， 若干次之后，你打开面前一扇门，发现只有一间屋子，没有门了。 你开始原路返回，每走回一间屋子，你数一次，走到入口的时候，你可以回答出你到底用这钥匙开了几扇门。

循环：你打开面前这扇门，看到屋里面还有一扇门，（这门可能跟前面打开的门一样大小（静），也可能门小了些（动）），你走过去，发现手中的钥匙还可以打开它，你推开门，发现里面还有一扇门，（前面门如果一样，这门也是一样，第二扇门如果相比第一扇门变小了，这扇门也比第二扇门变小了（动静如一，要么没有变化，要么同样的变化）），你继续打开这扇门，。。。，一直这样走下去。 入口处的人始终等不到你回去告诉他答案。

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int value;
};


int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}

void *malloc_z(int size)
{
    void *p = malloc(size);
    memset(p, 0, size);
    return p;
}

int main()
{
    struct TreeNode *root = malloc_z(sizeof(struct TreeNode));

    root->left = malloc_z(sizeof(struct TreeNode));
    root->right = malloc_z(sizeof(struct TreeNode));
    root->value = 1;

    //root->right->left = NULL;
    //root->right->right = NULL;

    root->left->left = malloc_z(sizeof(struct TreeNode));
    //root->left->right = NULL;
    root->left->left->left = malloc_z(sizeof(struct TreeNode));
    //root->left->left->right = NULL;
    root->left->left->left->left = malloc_z(sizeof(struct TreeNode));
    //root->left->left->left->right = NULL;
    //root->left->left->left->left->left = NULL;
    //root->left->left->left->left->right = NULL;

    printf("the depth is %d\n", maxDepth(root));

    return 0;
}




