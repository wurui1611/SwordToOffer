#include <iostream>
#include <vector>
#include <string>

using namespace std;

//剑指offer 05 替换空格
/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

输入：s = "We are happy."
输出："We%20are%20happy."
*/
class SOlution{
public:
    string replaceSpace(string s){
        string res = "";
        for(auto c:s){
            if(c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};