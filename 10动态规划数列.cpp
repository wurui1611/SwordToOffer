#include <bits/stdc++.h>

using namespace std;

//剑指 Offer 10- I. 斐波那契数列
/*
剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
class Solution{
public:
    int Fibonacci(int n){
        vector<int> fib(n + 1);
        fib.at(0) = 1;
        fib.at(1) = 1;

        for(int i = 2; i <= n; i++){
            fib.at(i) = (fib.at(i - 1) + fib.at(i - 2)) % 1000000007;
        }

        return fib.at(n);

        //..空间压缩
        if (n == 0 || n == 1) return n;
        int pre = 0, cur = 1;
        int res;
        for (int i = 2; i <= n; i++){
            res = (pre + cur) % 1000000007;
            pre = cur;
            cur = res;
        }
        return res;
        //..记忆数组，考虑递归重复计算问题
        vector<int> memo(n + 1);
        return helper(n, memo);



        //..数学公式
        double root5 = sqrt(5);
        return (1 / root5) * ((pow((1 + root5) / 2, n + 1) - pow((1 - root5) / 2, n + 1)));
    }
    int helper(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] > 0) return memo[n];

        return memo[n] = (helper(n - 1, memo) + helper(n - 2, memo));
    }
};

//剑指 Offer 10- II. 青蛙跳台阶问题
/*
剑指 Offer 10- II. 青蛙跳台阶问题
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1
提示：

0 <= n <= 100
*/
class Solution{
public:
    int numWays(int n){
        vector<int> dp(101); //
        dp.at(0) = 1;
        dp.at(1) = 1;

        for(int i = 2; i <= n; i++){
            dp.at(i) = (dp.at(i - 1) + dp.at(i - 2)) % 1000000007;
        }

        return dp.at(n);
    }
};
