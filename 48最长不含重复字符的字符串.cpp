#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//剑指offer 48 朢�长不含重复字符的子字符串
/*
请从字符串中找出丢�个最长的不包含重复字符的子字符串，计算该朢�长子字符串的长度〄1�7

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的朢�长子串是 "abc"，所以其长度丄1�7 3〄1�7

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的朢�长子串是 "b"，所以其长度丄1�7 1〄1�7

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的朢�长子串是 "wke"，所以其长度丄1�7 3〄1�7
     请注意，你的答案必须昄1�7 子串 的长度，"pwke" 是一个子序列，不是子串��1�7

*/
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int res = 0, head = 0, tail = 0;

        unordered_map<int, int> nMap;
        while (tail < s.length()){
            if (nMap.find(s[tail]) != nMap.end()) head = max(nMap[s[tail]] + 1, head);

            nMap[s[tail]] = tail;
            tail++;

            res = max(res, tail - head);
        }

        return res;




        int start(0), end(0), len(0), res(0);

        while (end < s.length()) {
            char tmp = s[end];

            for (int i = start; i < end; ++i) {
                if (tmp == s[i]) {
                    start = i + 1;
                    len = end - start;
                    break;

                }
            }

            end++;
            len++;

            res = max(res, len);

        }

        return res;
    }

};