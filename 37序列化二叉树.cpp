#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

//剑指offer 37 序列化二叉树
/*
请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
class Solution{
public:
    string serialize(TreeNode* root){// 利用队列， 
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();

            if (tmp){
                out << tmp->val << " ";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else out << "null ";
        }

        return out.str();
    }
    TreeNode* deserialize(string data){
        istringstream input(data);
        string val;
        vector<TreeNode*> res;

        while (input >> val){
            if (val == "null") res.push_back(NULL);
            else res.push_back(new TreeNode(stoi(val))); 
        }

        int j = 1;
        for (int i = 0; j < res.size(); i++){
            if (res[i] == NULL) continue;
            if (j < res.size()) res[i]->left = res[j++];
            if (j < res.size()) res[i]->right = res[j++];
        }

        return res[0];
    }
};