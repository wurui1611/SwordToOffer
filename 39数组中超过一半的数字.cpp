#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//剑指offer 39 数组中出现次数超过一半的数字
/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
*/
class Solution{
public:
    int majorityElement(vector<int> &nums){
        //排序
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

        //设置计数
        int count = 0, j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == nums[j]) count++;
            else count--;
            if (count == 0) j = i + 1;
        }
        return nums[j];
    }
};