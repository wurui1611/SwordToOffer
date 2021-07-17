#include <iostream>

using namespace std;

//剑指offer 15 二进制中 1 的个数 汉明距离 位运算
class Solution{
public:
    int hammingWeight(uint32_t n){
        int res = 0;
        while(n){
            if(n & 1) res++;
            n >>= 1;
        }
        return res;

        int count = 0;
        while (n != 0){
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};