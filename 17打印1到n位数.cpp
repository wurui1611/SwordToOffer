#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//剑指offer 17 打印仄1�7 1 刄1�7 朢�大的n位数
/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数��比如输兄1�7 3，则打印凄1�7 1〄1�72〄1�73 丢�直到朢�大的 3 位数 999〄1�7

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
*/
class Solution{
public:
    vector<int> printNumbers(int n){
        long limit = pow(10, n);
        vector<int> res;
        for(int i = 1; i < limit; i++) res.push_back(i);
        return res;

        
    }
};