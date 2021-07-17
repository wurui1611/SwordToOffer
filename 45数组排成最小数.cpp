#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//剑指offer 45 把数组排成最小的数 中等 字符串 排序
/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

输入: [10,2]
输出: "102"

输入: [3,30,34,5,9]
输出: "3033459"

*/
class Solution{
public:
    string minNumber(vector<int> &nums){
        vector<string> strs;
        string res;

        for (auto data:nums) strs.push_back(to_string(data));//..先转成 字符串

        sort(strs.begin(), strs.end(), [](string s1, string s2){return s1 + s2 < s2 + s1;});//..前后字符串相加，比较

        for (auto s:strs) res += s;

        return res;
    }
};