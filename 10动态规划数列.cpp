#include <bits/stdc++.h>

using namespace std;

//��ָ Offer 10- I. 쳲���������
/*
��ָ Offer 10- I. 쳲���������
дһ������������ n ����쳲�������Fibonacci�����еĵ� n ��� F(N)����쳲��������еĶ������£�

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), ���� N > 1.
쳲����������� 0 �� 1 ��ʼ��֮���쳲�������������֮ǰ��������Ӷ��ó���

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��
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

        //..�ռ�ѹ��
        if (n == 0 || n == 1) return n;
        int pre = 0, cur = 1;
        int res;
        for (int i = 2; i <= n; i++){
            res = (pre + cur) % 1000000007;
            pre = cur;
            cur = res;
        }
        return res;
        //..�������飬���ǵݹ��ظ���������
        vector<int> memo(n + 1);
        return helper(n, memo);



        //..��ѧ��ʽ
        double root5 = sqrt(5);
        return (1 / root5) * ((pow((1 + root5) / 2, n + 1) - pow((1 - root5) / 2, n + 1)));
    }
    int helper(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] > 0) return memo[n];

        return memo[n] = (helper(n - 1, memo) + helper(n - 2, memo));
    }
};

//��ָ Offer 10- II. ������̨������
/*
��ָ Offer 10- II. ������̨������
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n ����̨���ܹ��ж�����������

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��

ʾ�� 1��

���룺n = 2
�����2
ʾ�� 2��

���룺n = 7
�����21
ʾ�� 3��

���룺n = 0
�����1
��ʾ��

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
