#include <iostream>
#include <vector>

using namespace std;

//..��ָ Offer 63. ��Ʊ��������� �е�
/*
�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
�0�2

���ƣ�

0 <= ���鳤�� <= 10^5

*/
class Solution{
public:
    int maxProfit(vector<int> &prices){
        int minPrice = INT32_MAX;
        int maxProfit = 0;

        for (auto price:prices){
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};