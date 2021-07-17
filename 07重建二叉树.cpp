#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/

using namespace std;

//剑指offer 07 重建二叉树 中等
/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    TreeNode* rebuild(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }
    TreeNode* helper(vector<int>& preorder, int pre_begin, int pre_end, vector<int>& inorder, int in_begin, int in_end) {
        if (pre_begin > pre_end) return nullptr;

        int rootval = preorder[pre_begin];
        int idx;
        for (int i = in_begin; i <= in_end; ++i) {
            if (inorder[i] == rootval) {
                idx = i;
                break;

            }
        }

        int leftsize = idx - in_begin;        TreeNode* root = new TreeNode(rootval);

        root->left = helper(preorder, pre_begin + 1, pre_begin + leftsize, inorder, in_begin, idx - 1);
        root->right = helper(preorder, pre_begin + leftsize + 1, pre_end, inorder, idx + 1, in_end);

        return root;
    }
};
class Solution{
public:
    TreeNode* rebuild(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }
    TreeNode* helper(vector<int>& inorder, int in_begin, int in_end, vector<int>& postorder, int post_begin, int post_end) {
        if (post_begin > post_end) return nullptr;

        int idx;
        int rootval = postorder[post_end];

        for (int i = in_begin; i <= in_end; ++i) {
            if (inorder[i] == rootval) {
                idx = i;
                break;

            }
        }

        int leftsize = idx - in_begin;
        TreeNode* root = new TreeNode(rootval);

        root->left = helper(inorder, in_begin, idx - 1, postorder, post_begin, post_begin + leftsize - 1);
        root->right = helper(inorder, idx + 1, in_end, postorder, post_begin + leftsize, post_end - 1);

        return root;
    }
};



class Solution{
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
        // 递归分治
        return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        //利用先序遍历和中序遍历的特性  先序遍历 根 左 右  中序遍历 左 根 右
    }
    // 递归分治
    TreeNode* recursionBuild(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, 
                            vector<int>::iterator in_begin, vector<int>::iterator in_end){
        if(in_end == in_begin) return NULL; // 判断中序区间前后是否相等， 没有考虑前序遍历区间前后是否相等的情况

        TreeNode* cur = new TreeNode(*pre_begin);// 二叉树的根节点 根据前序遍历 根 左 右 确定根节点
        auto root = find(in_begin, in_end, *pre_begin);// 找到 中序遍历 根节点的位置

        // 重构左子树
        cur->left  = recursionBuild(pre_begin + 1, pre_begin + 1 + (root - in_begin), in_begin, root);
        // 重构右子树
        cur->right = recursionBuild(pre_begin + 1 + (root - in_begin), pre_end,  root + 1, in_end);

        return cur;
    }

    TreeNode* buildTree2(vector<int> &inorder, vector<int> &postorder) {
        return recursionBuild2(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());

    }
    TreeNode* recursionBuild2(vector<int>::iterator in_begin, vector<int>::iterator in_end, vector<int>::iterator post_begin, vector<int>::iterator post_end){
        if (in_end == in_begin) return nullptr;

        TreeNode* cur = new TreeNode(*post_end);
        auto root = find(in_begin, in_end, *post_end);

        cur->left = recursionBuild2(in_begin, root, post_begin + 1, post_begin + 1 + (root - in_begin));
        cur->right = recursionBuild2(root + 1, in_end, post_begin + 1 + (root - in_begin), post_end);


        return cur;
    }
};