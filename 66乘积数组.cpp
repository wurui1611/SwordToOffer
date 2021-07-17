#include <iostream>
#include <vector>

using namespace std;

//..��ָ Offer 66. �����˻�����
/*
����һ������ A[0,1,��,n-1]���빹��һ������ B[0,1,��,n-1]��
���Ё0�2B[i] ��ֵ������ A �г����±� i �����Ԫ�صĻ�, 
���0�2B[i]=A[0]��A[1]������A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����

�0�2

ʾ��:

����: [1,2,3,4,5]
���: [120,60,40,30,24]
�0�2

��ʾ��

����Ԫ�س˻�֮�Ͳ������ 32 λ����
a.length <= 100000

*/
class Solution{
public:
    vector<int> constructArr(vector<int> &nums){
        vector<int> res;

        int left = 1;
        for (int i = 0; i <nums.size(); i++){
            res[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for (int j = nums.size() - 1; j >= 0; j--){
            res[j] *= right;
            right *= nums[j];
        }

        return res;
    }
};