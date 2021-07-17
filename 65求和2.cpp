#include <iostream>

using namespace std;

//剑指offer 65 不用加减乘除做加法
/*
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

输入: a = 1, b = 1
输出: 2
 
提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数
*/
class Solution{
public:
    int twoSum(int a, int b){
        while (b){
            int carry = (unsigned)(a&b) << 1;// keypoint
            a ^= b;
            b = carry;
        }

        return a;
    }
};
