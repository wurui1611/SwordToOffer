#include <iostream>
#include <vector>

using namespace std;

//..剑指offer 54 二叉搜索树的第 k 大节点 中序遍历
/*
给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

*/
//..定义二叉树
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
//..搜索二叉树第 k 大节点的类
class Solution{
public:
    int kthNode(TreeNode* root, int k){
        vector<int> res;

        inorder(root, res);

        return res[k - 1];
    }
    void inorder(TreeNode* root, vector<int> &nums){
        if (root == NULL) return ; //..边界条件

        inorder(root->left, nums); //..左
        nums.push_back(root->val); //..根
        inorder(root->right, nums); //..右
    }
};