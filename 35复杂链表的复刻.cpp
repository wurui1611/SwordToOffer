#include <iostream>
#include <unordered_map>

using namespace std;

//剑指offer 35 复杂链表的复刻
/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 
指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

*/
struct Node{
    int val;
    Node* next;
    Node* random;
    Node(int x): val(x), next(NULL), random(NULL){};
};
class Solution{
public:
    Node* copyRandomList(Node* head){
        if (head == NULL) return head;// 边界条件
        unordered_map<Node*, Node*> hMap; // 利用哈希表 储存头节点和 next random 节点
        Node* tmp = head;
        //将所有节点先遍历到hashmap中
        while (tmp != NULL){
            hMap[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }

        //连接 next 和 random 节点
        tmp = head;
        while (tmp != NULL){
            if (tmp->next) hMap[tmp]->next = hMap[tmp->next];
            if (tmp->random) hMap[tmp]->random = hMap[tmp->random];
        }

        return hMap[head];
    }
};