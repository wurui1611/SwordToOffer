#include <iostream>
#include <vector>

using namespace std;

//..剑指 Offer 66. 构建乘积数组
/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
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