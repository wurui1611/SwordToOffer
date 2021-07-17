#include <iostream>

using namespace std;

//剑指offer 43 1 - n 中 1 的个数 中等
/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

输入：n = 12
输出：5

输入：n = 13
输出：6

*/
class Solution{
public:
    int countDigitOne(int n){
        long digit = 1;
        long res = 0;

        long high = n / 10, low = 0, cur = n % 10;
        while (high != 0 || cur != 0){
            if (cur == 0) res += high * digit;
            else if (cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;

            low += cur * digit;
            cur = high % 10;
            high = n / 10;
            digit *= 10;
        }

        return res;
    }
};
