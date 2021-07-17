#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

//剑指offer 32-I 从上到下打印二叉树 中等
/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[3, 9, 20, 15, 7]

*/
class Solution{
public:
    vector<int> printTree(TreeNode* root){
        vector<int> res;
        if(root == NULL) return res;//边界条件 判空

        queue<TreeNode*> q;//利用队列
        q.push(root);
        TreeNode* tmp;
        while(!q.empty()){//先序遍历
            tmp = q.front();//根
            res.push_back(tmp->val);
            q.pop();

            if(tmp->left) q.push(tmp->left);//左
            if(tmp->right) q.push(tmp->right);//右
        }

        return res;
    }
};

//剑指offer 32-II 从上到下打印二叉树
/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/
class Solution{
public:
    vector<vector<int>> printTree(TreeNode* root){
        vector<vector<int>> res;
        if(root == NULL) return res;// 判空

        queue<TreeNode*> q;// 队列
        q.push(root);

        while(!q.empty()){
            vector<int> tmp;
            int l = q.size();
            for(int i = 0; i < l; i++){
                TreeNode* r = q.front();//根
                tmp.push_back(r->val);
                q.pop();

                if(r->left) q.push(r->left);//左
                if(r->right) q.push(r->right);//右
            }
            res.push_back(tmp);
        }

        return res;
    }
};

//剑指offer 32-III 从上到下打印二叉树
/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
*/
class Solution{
public:
    vector<vector<int>> printTree(TreeNode* root){
        vector<vector<int>> res;
        if(root == NULL) return res;//判空

        deque<TreeNode*> d;//双端队列
        d.push_back(root);
        bool flag = true;

        while(!d.empty()){
            int n = d.size();
            vector<int> tmp;
            TreeNode* r;

            while(n > 0){// 第一层 三 五 。。。
                if(flag){// 前取后放
                    r = d.front(); //前
                    d.pop_front();

                    if(r->left) d.push_back(r->left);//左
                    if(r->right) d.push_back(r->right);//右
                }
                else{// 第二层 四 六 。。。
                    r = d.back();//后
                    d.pop_back();

                    if(r->right) d.push_front(r->right);//右
                    if(r->left) d.push_front(r->left);//左
                }

                tmp.push_back(r->val);
                n--;
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
};