#include <iostream>

using namespace std;

//剑指offer 22 链表中��数笄1�7 k 个节炄1�7
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* KthNode(ListNode* head, int k){
        ListNode* slow = head;
        ListNode* fast = head;


        //
        int len = 0;
        while (fast != nullptr) {
            fast = fast->next;
            ++len;

        }

        len -= k;
        if (len == 0) {
            fast = fast->next;
            return head;

        }
        else if (len < 0) return nullptr;

        fast = head;
        while(fast != NULL){
            fast = fast->next;

            if(k == 0) slow = slow->next;
            else k--;
        }
        return slow;
    }
};