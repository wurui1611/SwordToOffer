#include <iostream>
#include <vector>

using namespace std;

//剑指offer 51 数组中的逆序对 困难 归并排序 递归 合并
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

输入: [7,5,6,4]
输出: 5
*/
class Solution{
public:
    int reversePairs(vector<int> &nums){
        if(nums.size() == 0) return 0; //..边界条件

        vector<int> tmp(nums.size()); //..临时数组
        int count = mergeSort(nums, tmp, 0, nums.size() - 1);//..归并排序

        return count;
    }

    int mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right){
        if(left >= right) return 0; //..边界条件

        int mid = left + (right - left) / 2;
        int inv_count = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);

        int i = left, j = mid + 1, pos = left;

        while(i < mid && j < right){
            if(nums[i] < nums[j]){
                tmp[pos] = nums[i];
                i++;
                inv_count = j - (mid + 1);
            }
            else{
                tmp[pos] = nums[j];
                j++;
            }
            pos++;
        }

        for (int k = i; k <= mid; k++) {nums[pos++] = nums[k]; inv_count += (j - (mid + 1));}
        for (int k = j; k <= right; k++) {nums[pos++] = nums[k];}
        return inv_count;
    }
};