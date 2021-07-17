#include <iostream>

using namespace std;

//..剑指offer 52 两个链表的第一个公共节点
/*

*/
//..定义链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

//..寻找第一个公共节点的类
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* A, ListNode* B){
        ListNode* a = A;
        ListNode* b = B;

        while (a != b){
            if (a == NULL) a = B;
            else a = a->next;
            if (b == NULL) b = A;
            else b = b->next;
        }

        return a;
    }
};