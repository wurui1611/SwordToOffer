#include <iostream>
#include <vector>

using namespace std;

//剑指offer 53-I 在排序数组中查找 I
/*
统计一个数字在排序数组中出现的次数。

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
*/
class Solution{
public:
    int search(vector<int> &nums, int target){
        int count = 0;
        int id = findTargetId(nums, target);// 找到 target 在 数组里面的 第一个 id

        while (id < nums.size() && nums[id] == target){
            count++;
            id++;
        }

        return count;
    }
    int findTargetId(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;

        while (left < right){ // 二分查找
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};

//剑指offer 53-II 0 - n - 1 中缺失的数字
/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

输入: [0,1,3]
输出: 2

输入: [0,1,2,3,4,5,6,7,9]
输出: 8

*/
class Solution{
public:
    int missingNumber(vector<int> &nums){
        int left = 0, right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};