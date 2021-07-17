#include <iostream>

using namespace std;

//剑指offer 27 二叉树的镜像
/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution{
public:
    TreeNode* mirrorTree(TreeNode* root){
        //递归
        if(root != NULL){
            if(root->left != NULL || root->right != NULL){
                swap(root->left, root->right);//交换左右
                mirrorTree(root->left);//递归左子树
                mirrorTree(root->right);//递归右子树
            }
        }
        return root;
    }
};