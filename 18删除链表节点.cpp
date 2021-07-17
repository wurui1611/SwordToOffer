#include <iostream>

using namespace std;

//剑指offer 18 删除链表的节点
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* deleteNode(ListNode* head, int val){
        if(head == NULL) return head;// 边界条件 判空

        ListNode* cur = head;
        ListNode* tmp = head->next;// 后继节点

        if(tmp->val == val) return tmp;

        while(tmp != NULL){
            if(tmp->val == val){
                cur->next = tmp->next;//跳跃
                return head;
            }
            else{
                cur = cur->next;
                tmp = tmp->next;
            }
        }

        return head;
    }
};

ListNode* deleteListNode(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;

    while (pre->next) {
        ListNode* cur = pre->next;

        while (cur->next && cur->val == cur->next->val) cur = cur->next;

        if (cur != pre->next) pre->next = cur; // 降重  pre->next = cur->next 去除所有重复的元素
        else pre = pre->next;

    }

    return dummy->next;
}
//删除链表中所有重复节点
class Solution{
public:
    ListNode* deleteDuplications(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode *pre = res, *cur = head;

        while (cur){
            if (cur->next && cur->val == cur->next->val){
                cur = cur->next;
                while (cur->next && cur->val == cur->next->val){
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;
            }
            else {
                cur = cur->next;
                pre->next = cur;
            }
        }

        return res->next;
    }
};