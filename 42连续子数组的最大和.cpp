#include <iostream>
#include <vector>

using namespace std;

//..剑指offer 42 连续子数组的最大和
/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/
class Solution{
public:
    int sumOfSubArray(vector<int> &nums){
        int maxSum = nums[0];
        int sum = 0;

        for (auto data:nums){
            if (data > 0) sum += data;// 有增益
            else sum = data;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};