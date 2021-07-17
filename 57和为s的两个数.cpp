#include <iostream>
#include <vector>

using namespace std;

//剑指offer 56 和为 s 的两个数
/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

*/
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left != right){
            if (nums[left] + nums[right] < target) left++;
            else if (nums[left] + nums[right] > target) right--;
            else return {nums[left], nums[right]};
        }
        return {};
    }
};