#include <iostream>
#include <vector>

using namespace std;

//��ָ Offer 64. ��1+2+��+n �е� �ݹ�
/*
�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

�0�2

ʾ�� 1��

����: n = 3
���:�0�26
ʾ�� 2��

����: n = 9
���:�0�245
�0�2

���ƣ�

1 <= n�0�2<= 10000

*/
class Solution{
public:
    int sumNums(int n){
        int res = n;

        n > 1 && (res += sumNums(n - 1));

        return res;
    }
};