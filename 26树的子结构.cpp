#include <iostream>

using namespace std;

//剑指offer 26 树的子结构 中等
/*输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
class Solution{
public:
    bool isSubTree(TreeNode* A, TreeNode* B){
        if (A == NULL && B == NULL) return true;
        if (A == NULL || B == NULL) return false;

        return helper(A, B) || isSubTree(A->left, B) || isSubTree(A->right, B);
    }
    bool helper(TreeNode* A, TreeNode* B){
        if (B == NULL) return true;
        if (A == NULL) return false;
        if (A->val == B->val){
            if (helper(A->left, B->left) && helper(A->right, B->right)) return true;
            else return false;
        }
        else return false;
    }
};