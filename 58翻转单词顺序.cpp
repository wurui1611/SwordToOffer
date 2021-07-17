#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

//..剑指offer 58-I 翻转单词的顺序 栈
/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

输入: "the sky is blue"
输出: "blue is sky the"

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/
class Solution{
public:
    string reverse(string s){
        stack<string> sstack;
        string res, str;
        istringstream ss(s);

        while (ss >> str){
            sstack.push(str);
            sstack.push(" ");
        }

        if (!sstack.empty()) sstack.pop();//多余的空格

        while (!sstack.empty()){
            res += sstack.top();
            sstack.pop();
        }

        return res;
    }
};

//..剑指offer 58-II 左旋转字符串
/*

*/
class Solution{
public:
    string reverseLeftWords(string s, int k){
        string s1 = s.substr(0, k);
        string s2 = s.substr(k);
        return s2 + s1;

        return (s + s).substr(k, s.length());
    }
};
class SOlution{
public:
    string reverseLeftWords(string s, int k){
        //..三次翻转
        int len = s.length() - 1;
        if (len <= 1) return s;

        reverse(s, 0, k -1);
        reverse(s, k, len);
        reverse(s, 0, len);

        return s;
    }
    void reverse(string &s, int i, int j){
        while (i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
