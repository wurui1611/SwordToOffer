#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//剑指offer 14-I 减绳子 中等
/*
n = 2, mmax = 1 * 1 = 1;
n = 3, mmax = 1 * 2 = 2;
n = 4, res = 1, les = 1, mmax = 2 * 2 = 4, 分成两个2
n = 5 ,分成一个2，一个3
n = 6 都分成3
以此类推，尽量分出多个3，其余为2，这样构成的数最大

  x1 + x2 + ... + xn = l
  max(x1 * x2 * ... * xn)

  当所有绳子长度相等的时候， 乘积最大
  l = a * x;
  接近 常数 e 的时候最大
  选取 3 和 2 比较 3 更大一点
  所以 尽可能分成长度为 3 的段

*/
class Solution{
public:
    int cuttingRope(int n){
        int nmax, remainder = n % 3, index = n / 3;
        if(n <= 3) return 1*(n - 1);
        else{
            if(remainder == 0) return pow(3, index);
            else if(remainder == 1) return pow(3, index - 1)*2*2;
            else return pow(3, index)*2;
        }
        return -1;
    }
};