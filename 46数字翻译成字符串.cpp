#include <iostream>
#include <string>

using namespace std;

//剑指offer 46 把数字翻译成字符串 中等
/*

*/
class Solution{
public:
    int translateNum(int num){
        //滚动数组
        string str = to_string(num);
        int p = 0, q = 0, r = 1;

        for (int i = 0; i < str.length(); i++){
            q = p;
            p = r;
            r = 0;
            r += q;

            if (i == 0) continue;

            string tmp = str.substr(i - 1, 2);
            if (tmp <= "25" && tmp >= "0") r += p;
        }

        return r;

        //递归

        if (num < 10) return 1;

        if (num % 100 <= 25 && num % 100 >= 10) return translateNum(num / 10) + translateNum(num / 100);
        else return translateNum(num / 10);

    }
};