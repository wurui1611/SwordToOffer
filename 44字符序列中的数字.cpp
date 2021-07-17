#include <iostream>
#include <cmath>

using namespace std;

//剑指offer 44 数列中的数字
/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

输入：n = 3
输出：3

输入：n = 11
输出：0

规律：

  1 2 ... 9     10 11 12 ... 99     100 101 102 ... 999
    9个数           90 个数                 900 个数
    9 x 1位数       90 x 2位数            900 x 3位数
对于第 n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。

首先找到这个数字对应的数是几位数，用 digits 表示；
然后确定这个对应的数的数值 target；
最后确定返回值是 target 中的哪个数字。
举个栗子：

比如输入的 n 是 365：

经过第一步计算我们可以得到第 365 个数字表示的数是三位数，n= 365−9−90×2=176，digtis = 3。
这时 n=176 表示目标数字是三位数中的第 176 个数字。

我们设目标数字所在的数为 number，计算得到 number=100+176/3=158，
idx 是目标数字在 number 中的索引，如果 idx = 0，表示目标数字是 number - 1 中的最后一个数字。

根据步骤2，我们可以计算得到 idx = n % digits = 176 % 3 = 2，
说明目标数字应该是 number = 158 中的第二个数字，即输出为 5。

*/
class Solution{
public:
    int nthNumber(int n){
        long digit = 1;
        //long res = 0;

        while (n - 9 * pow(10, digit - 1) * digit > 0){
            n -= 9 * pow(10, digit - 1) * digit;
            digit++;
        }

        long res = pow(10, digit - 1) + n / digit;
        long mod = n % digit;
        if (mod == 0) return res - 1 % 10;
        else return res / (int)pow(10, digit - mod) % 10;
        return 0;
    }
};