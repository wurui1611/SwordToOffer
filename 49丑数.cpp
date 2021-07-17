#include <iostream>
#include <vector>

using namespace std;

//剑指offer 49 丑数 中等
/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

*/
class Solution{
public:
    int nLengthUglyNumber(int n){
        vector<int> dp(n + 1);
        dp.at(0) = 1;
        int p2, p3, p5;
        p2 = p3 = p5 = 0;

        for (int i = 1; i <= n; i++){
            dp.at(i) = min(min(2 * dp.at(p2), 3 * dp.at(p3)), 5 * dp.at(p5));

            if (dp.at(i) == 2 * dp.at(p2)) p2++;
            if (dp.at(i) == 3 * dp.at(p3)) p3++;
            if (dp.at(i) == 5 * dp.at(p5)) p5++;
        }

        return dp.at(n - 1);
    }
};