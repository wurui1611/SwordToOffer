#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//剑指offer 50 第一个只出现一次的字符
/*

*/
class Solution{
public:
    char firstUnique(string s){
        if (s == "") return ' ';
        if (s.length() == 1) return s[0];

        unordered_map<char, int> sMap;
        for (auto c:s) ++sMap[c];
        for (auto c:s){
            if (sMap[c] == 1) return c;
        }

        return ' ';
    }
};
