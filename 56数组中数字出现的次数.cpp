#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//..剑指offer 56-I 数组中数字出现的次数 中等 异或
/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

*/
class Solution{
public:
    vector<int> singleNumbers(vector<int> &nums){
        int s = 0;
        for (auto data:nums) s ^= data;
        s ^= -s;

        int res1 = 0, res2 = 0;
        for (auto data:nums){
            if (s & data) res1 ^= data;
            else res2 ^= data;
        }

        return {res1, res2};
    }
};

//..剑指offer 56-II 数组中数字出现的次数 中等
/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

输入：nums = [3,4,3,3]
输出：4

输入：nums = [9,1,7,9,7,9,7]
输出：1

//..位运算
1. 值得注意的是：如果某个数字出现3次，那么这个3个数字的和肯定能被3整除，则其对应二进制位的每一位的和也能被3整除
2. 统计数组中每个数字的二进制中每一位的和，判断该和是否能被3整除。
3. 若可以，则只出现一次的数字的二进制数中那一位为0，否则为1

*/
class Solution{
public:
    int singleNumber(vector<int> &nums){
        //hashmap
        unordered_map<int, int> nMap;
        for (auto data:nums) ++nMap[data];
        for (auto data:nums){
            if (nMap[data] == 1) return data;
        }
        return 0;

        //位运算
        int count = 0;
        int res = 0;
        for (int i = 0; i < 31; i++){
            int tmp = 0;
            for (auto data:nums){
                if (data & (1<<i)) count++;//..统计 每个数字的每一个二进制位上 1 的个数
            }

            if (count % 3 == 1) res ^= (1<<i); //..不能被 3 整除 说明那个二进制位的 1 是 单独数字的二进制位上面的 1
        }
        return res;
    }
};