#include <iostream>
#include <vector>

using namespace std;

//剑指offer 33 二叉搜索树的后序遍历序列 中等
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true

后序遍历： 左 右 根
*/
class Solution{
public:
    bool verifyPostorder(vector<int> &postorder){
        bool res = true;

        if (postorder.size() == 0) return res;// 边界条件

        res = helper(postorder, 0, postorder.size() - 1);

        return res;
    }
    bool helper(vector<int> &postorder, int start, int end){
        if (postorder.size() == 0 || start > end) return true;

        //根据后序遍历特性，确定根节点
        int root = postorder[end];

        //根据根节点确定，左子树和右子树
        int i = start;
        for (; i < end; i++){
            if (postorder[i] > root) break;
        }
        
        for (int j = i; j < end; j++){
            if (postorder[j] < root) return false;
        }

        bool left = true;
        if (i > start) left = helper(postorder, start, i -1);
        bool right = true;
        if (i < end - 1) right = helper(postorder, i, end - 1);

        return left && right;
    }
};