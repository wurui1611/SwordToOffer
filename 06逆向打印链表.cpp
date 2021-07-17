#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//剑指offer 06 从尾到头打印链表 栈
/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

输入：head = [1,3,2]
输出：[2,3,1]
*/
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    vector<int> printListNode(ListNode* head){
        stack<ListNode*> _stack;//建栈
        vector<int> res;
        while (head != NULL){//将链表里的节点传入栈
            _stack.push(head);
            head = head->next;
        }
        
        ListNode* tmp = new ListNode(0);//申请新的链表
        while(!_stack.empty()){//栈先入后出， 正好可以从尾到头输出链表的值
            tmp = _stack.top();
            res.push_back(tmp->val);
            _stack.pop();
        }

        return res;
    }
};