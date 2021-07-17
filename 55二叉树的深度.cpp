#include <iostream>
#include <queue>

using namespace std;

//..剑指offer 55-I 二叉树的深度
/*
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        //..DFS 先序遍历， 中序遍历， 后序遍历 深度优先搜索
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        //最小深度
        if (root == NULL) return 0;
        //int m = minDepth(root->left);
        //int n = minDepth(root->right);
        //return root->left == NULL || root->right == NULL ? m + n + 1 : min(m, n) + 1;

        //..BFS 层序遍历 广度优先搜索 设置队列
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while (!q.empty()){
            int size = q.size();// key

            for (int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res++;
        }

        return res;
    }
};

//..剑指offer 55-II 平衡二叉树
/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，
那么它就是一棵平衡二叉树。

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
*/
class Solution{
public:
    bool isBalanced(TreeNode* root){
        if (root == NULL) return true;

        int depth = 0;

        return isBalancedHelper(root, depth);
    }
    bool isBalancedHelper(TreeNode* root, int &depth){
        if (root == NULL) {depth = 0; return true;}

        int left = 0, right = 0;
        if (isBalancedHelper(root->left, left) && isBalancedHelper(root->right, right)){
            int diff = left - right;
            if (abs(diff) <= 1){
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }

        return false;
    }
};