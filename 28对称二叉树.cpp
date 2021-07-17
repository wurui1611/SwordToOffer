#include <iostream>

using namespace std;

//剑指offer 28 对称的二叉树
/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

输入：root = [1,2,2,3,4,4,3]
输出：true

输入：root = [1,2,2,null,3,null,3]
输出：false
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution{
public:
    bool isSymmetric(TreeNode* root){
        bool res = true;
        if(root != NULL){
            res = helper(root->left, root->right);
        }
        return res;

    }
    bool helper(TreeNode* A, TreeNode* B){
        if(A == NULL && B == NULL) return true;
        if(A == NULL || B == NULL) return false;
        if(A->val != B->val) return false;
        return helper(A->left, B->right) && helper(A->right, B->left);
    }
};