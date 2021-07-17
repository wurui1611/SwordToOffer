#include <iostream>
#include <vector>

using namespace std;

//剑指offer 11 旋转数组中最小的数字 二分泄1�7
/*
把一个数组最弢�始的若干个元素搬到数组的末尾，我们称之为数组的旋转��1�7
输入丢�个��增排序的数组的丢�个旋转，输出旋转数组的最小元素��1�7
例如，数组 [3,4,5,1,2] 丄1�7 [1,2,3,4,5] 的一个旋转，该数组的朢�小��为1。 1�7

示例 1＄1�7
输入：[3,4,5,1,2]
输出＄1�71
示例 2＄1�7

输入：[2,2,2,0,1]
输出＄1�70
*/
class Solution{
public:
    int findMinNumber(vector<int> &nums){
        //˳�����
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]) return nums[i + 1];
        }

        return nums[0];

        //���ֲ���
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == nums[end]) end--;
            else if(nums[mid] > nums[end]) start = mid + 1;
            else end = mid;
        }

        return nums[start];
    }
};

class Solution{
public:
    int findTarget(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[l] == target) return l;
            else if (nums[l] == nums[mid]) {
                ++l;
            }
            else if (nums[l] < nums[mid]) {
                if (nums[l] > target || nums[mid] < target) l = mid;
                else {
                    ++l;
                    r = mid - 1;
                }
            }
            else if (nums[l] > nums[mid]) {
                if (nums[l] > target && nums[mid] < target) l = mid;
                else {
                    ++l;
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};