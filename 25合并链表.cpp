#include <iostream>

using namespace std;

//剑指offer 25 合并两个有序链表
/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* p = head;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        //考虑链表长短
        if(l1 != NULL) p->next = l1;
        if(l2 != NULL) p->next = l2;

        return head->next;
    }
};
