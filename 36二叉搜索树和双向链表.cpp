#include <iostream>

using namespace std;

//剑指offer 36 二叉搜索树和双向链表
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(){}

    Node(int x): val(x), left(NULL), right(NULL){};

    Node(int x, Node* _left, Node* _right): val(x), left(_left), right(_right){};
};
class Solution{
public:
    Node* treeToDoublyList(Node* root){
        if (!root) return NULL;

        Node* head = NULL, *pre = NULL; //头节点和前驱节点
        helper(root, head, pre);

        //建环
        head->left = pre;
        pre->right = head;

        return head;
    }
    void helper(Node* root, Node* &head, Node* &pre){
        if (!root) return ;// 边界条件

        helper(root->left, head, pre);// 左
        //根
        if (!head){
            head = root;
            pre = root;
        }
        else {
            pre->right = root;
            root->left = pre;
            root = pre;
        }

        helper(root->right, head, pre);//右
    }
};