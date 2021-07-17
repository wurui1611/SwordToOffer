#include <iostream>
#include <vector>
#include <set>

using namespace std;

//..剑指 Offer 61. 扑克牌中的顺子
/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .

*/
class Solution{
public:
    bool isStraight(vector<int> &nums){
        set<int> nSet; // 闄嶉噸
        int maxnum = 0, minnum = 14;

        for (auto data:nums){
            if (data == 0) continue;

            maxnum = max(data, maxnum);
            minnum = min(data, minnum);
            if (nSet.find(data) != nSet.end()) return false;

            nSet.insert(data);
        }

        return maxnum - minnum < 5;
    }
};