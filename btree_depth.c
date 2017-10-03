
/*
 * 常见算法题，求二叉树的深度，采用递归的方法
 * 需要理解递归的含义
 *
 * 可以参考简书上这篇文章
 * http://www.jianshu.com/p/4db970d8ddc1
 *
递归：你打开面前这扇门，看到屋里面还有一扇门（这门可能跟前面打开的门一样大小（静），也可能门小了些（动）），你走过去，发现手中的钥匙还可以打开它，你推开门，发现里面还有一扇门，你继续打开，。。。， 若干次之后，你打开面前一扇门，发现只有一间屋子，没有门了。 你开始原路返回，每走回一间屋子，你数一次，走到入口的时候，你可以回答出你到底用这钥匙开了几扇门。

递归就是有去（递去）有回（归来）。

具体来说，为什么可以”有去“？ 
这要求递归的问题需要是可以用同样的解题思路来回答除了规模大小不同其他完全一样的问题。

为什么可以”有回“？
这要求这些问题不断从大到小，从近及远的过程中，会有一个终点，一个临界点，一个baseline，一个你到了那个点就不用再往更小，更远的地方走下去的点，然后从那个点开始，原路返回到原点。

作者：紫松
链接：http://www.jianshu.com/p/4db970d8ddc1
來源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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




