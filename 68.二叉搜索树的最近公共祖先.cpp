#include <iostream>

using namespace std;

//..��ָ Offer 68 - I. �����������������������
/*
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶���������:�0�2 root =�0�2[6,2,8,0,4,7,9,null,null,3,5]



�0�2

ʾ�� 1:

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
���: 6 
����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��
ʾ�� 2:

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
���: 2
����: �ڵ� 2 �ͽڵ� 4 ��������������� 2, ��Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��
�0�2

˵��:

���нڵ��ֵ����Ψһ�ġ�
p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ����������С�

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
    TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val - p->val) * (root->val - q->val) <= 0) return root;

        if (root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);

        return nullptr;

        //....��ָ Offer 68 - II. �������������������
        
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (l == nullptr) return r;
        if (r == nullptr) return l;

        if (l && r) return root;

        return root;
    }
};