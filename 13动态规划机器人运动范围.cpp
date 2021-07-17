#include <iostream>
#include <vector>
#include <set>

using namespace std;

//剑指offer 13 机器人的运动范围 中等 动态规划 深度优先搜索 利用 set 降重 
/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，
因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

输入：m = 2, n = 3, k = 1
输出：3

输入：m = 3, n = 1, k = 0
输出：1

*/
class Solution{
public:
    int movingCount(int m, int n, int k){
        set<pair<int, int>> marked;// set 降重

        dfs(marked, m, n, k, 0, 0);// 从 (0, 0) 开始深度优先搜索

        return marked.size();
    }
    int sumOfDigits(int x, int y){// 计算位序和
        int sum = 0;
        while (x > 0){
            sum += x % 10;
            x /= 10;
        }
        while (y > 0){
            sum += y % 10;
            y /= 10;
        }

        return sum;
    }
    void dfs(set<pair<int, int>> &marked, int m, int n, int k, int i, int j){
        if (i == m || j == n || sumOfDigits(i, j) > k || marked.find({i, j}) != marked.end()) return ;// 边界条件

        marked.insert({i, j});
        dfs(marked, m, n, k, i + 1, j);//行深度优先搜索
        dfs(marked, m, n, k, i, j + 1);//列深度优先搜索
    }
};