#include <iostream>

using namespace std;

//剑指offer 16 数值的整数次方 快速幂 中等
/*
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

示例 1:

输入: 2.00000, 10
输出: 1024.00000

示例 2:

输入: 2.10000, 3
输出: 9.26100

示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/
class Solution{
public:
    double power(double x, int n){
        if(x == 0) return 0;

        double res = 1;
        long b = n;

        if(b < 0){
            b = -b;
            x = 1 / x;
        }
        //快速幂
        while(b){
            if(b & 1) res *= x;
            x *= x;
            b >>= 1;
        }

        return res;
    }
};