#include <iostream>
#include <vector>
#include <set>

using namespace std;

//..��ָ Offer 61. �˿����е�˳��
/*
���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��

ʾ���0�21:

����: [1,2,3,4,5]
���: True
�0�2

ʾ���0�22:

����: [0,0,1,2,5]
���: True
�0�2

���ƣ�

���鳤��Ϊ 5�0�2

�������ȡֵΪ [0, 13] .

*/
class Solution{
public:
    bool isStraight(vector<int> &nums){
        set<int> nSet; // 降重
        int maxnum = 0, minnum = 14;

        for (auto data:nums){
            if (data == 0) continue;

            maxnum = max(data, maxnum);
            minnum = min(data, minnum);
            if (nSet.find(data) != nSet.end()) return false;

            nSet.insert(data);
        }

        return maxnum - minnum < 5;
    }
};