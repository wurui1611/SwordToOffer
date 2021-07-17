#include <iostream>
#include <string>

using namespace std;

//剑指offer 20 表示数值的字符串
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，

但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。

*/
class Solution{
public:
    bool stringToInteger(string s){
        int i = s.find_first_not_of(' ');
        if (i == string::npos) return false;
        int j = s.find_last_not_of(' ');
        s.substr(i, j - i + 1);
        if (s.empty()) return false;

        int e = s.find('e');
        int E = s.find('E');

        if (e == string::npos) return judgeP(s.substr(0, e));
        else return judgeP(s.substr(0, e)) && judgeS(s.substr(e + 1));

        if (E == string::npos) return judgeP(s.substr(0, E));
        else return judgeP(s.substr(0, E)) && judgeS(s.substr(E + 1));

        return false;
    }
    bool judgeP(string s){// 判断底数合不合法
        bool res = false, point = false;
        int len = s.length();

        for (int i = 0; i < len; i++){
            if (s[i] == '+' || s[i] == '-'){
                if (i != 0) return false;
            }
            else if (s[i] == '.'){
                if (point) return false;
                point = true;
            }
            else if (s[i] < '0' || s[i] > '9') return false;
            else res = true;
        }

        return res;
    }
    bool judgeS(string s){//判断指数是否合法
        bool res = false;
        int len = s.length();

        for (int i = 0; i < len; i++){
            if (s[i] == '+' || s[i] == '-'){
                if (i != 0) return false;
            }
            else if (s[i] < '0' || s[i] > 9) return false;
            else res = true;
        }

        return res;
    }
};