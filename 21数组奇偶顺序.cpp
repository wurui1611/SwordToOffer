#include <iostream>
#include <vector>

using namespace std;

//剑指offer 21 调整数组顺序使奇数位于偶数前面
/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。

*/
class Solution{
public:
    vector<int> exchange(vector<int> &nums){
        vector<int> res;
        for(auto data:nums){
            if(data % 2 == 0) res.push_back(data);
            else res.insert(res.begin(), data);
        }
        return res;
    }
};