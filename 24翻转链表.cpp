#include <iostream>

using namespace std;

//剑指offer 24 反转链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* current = NULL, *pre = head;
        while(pre != NULL){
            ListNode* tmp = pre->next;
            pre->next = current;
            current = pre;
            pre = tmp;
        }
        return current;
    }
};