#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//剑指offer 38 字符串的全排列 回溯算法 中等
/*
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]

*/
class Solution{
public:
    vector<string> permutation(string s){
        set<string> res;// 利用 set 降重

        backtrack(s, 0, res);

        return vector<string>(res.begin(), res.end());
    }
    void backtrack(string s, int start, set<string> &res){
        if (start == s.length()) {res.insert(s); return ;}

        for (int i = start; i < s.length(); i++){
            swap(s[i], s[start]);
            backtrack(s, start + 1, res);
            swap(s[i], s[start]);
        }
    }
};