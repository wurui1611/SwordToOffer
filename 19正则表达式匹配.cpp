#include <iostream>
#include <string>
#include <vector>

using namespace std;

//剑指offer 19 正则表达式匹酄1�7 困难  动��规刄1�7 回溯 
/*
请实现一个函数用来匹配包各1�7'. '咄1�7'*'的正则表达式〄1�7
模式中的字符'.'表示任意丢�个字符，耄1�7'*'表示它前面的字符可以出现任意次（各1�70次）〄1�7
在本题中，匹配是指字符串的所有字符匹配整个模式��1�7
例如，字符串"aaa"与模弄1�7"a.a"咄1�7"ab*ac*a"匹配，但丄1�7"aa.a"咄1�7"ab*a"均不匹配〄1�7

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串��1�7
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元約1�7, 在这里前面的元素就是 'a'。因此，字符丄1�7 "aa" 可被视为 'a' 重复了一次��1�7
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个＄1�7'*'）任意字符（'.'）��1�7
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 丄1�7 0 丄1�7, 'a' 被重复一次��因此可以匹配字符串 "aab"〄1�7
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
s 可能为空，且只包含从 a-z 的小写字母��1�7
p 可能为空，且只包含从 a-z 的小写字母以及字符1�7. 和1�7*，无连续的1�7 '*'〄1�7

状��1�7
很容易想到，dp[i][j] 表示的状态是 s 的前 i 项和 p 的前 j 项是否匹配��1�7

转移方程
现在如果已知亄1�7 dp[i-1][j-1] 的状态，我们该如何确宄1�7 dp[i][j] 的状态呢＄1�7
我们可以分三种情况讨论，其中，前两种情况考虑了所有能匹配的情况，剩下的就是不能匹配的情况了：

s[i] == p[j] or p[j] == '.'：比妄1�7 abb 咄1�7 abb，或耄1�7 abb 咄1�7 ab. ，很容易得到 dp[i][j] = dp[i-1][j-1] = True。因丄1�7 ab 咄1�7 ab 是匹配的，如果后面分别加丢�丄1�7 b，或耄1�7 s 加一丄1�7 b 耄1�7 p 加一丄1�7 . ，仍然是匹配的��1�7

p[j] == '*'：当 p[j] 为星号时，由于星号与前面的字符相关，因此我们比较星号前面的字笄1�7 p[j-1] 咄1�7 s[i] 的关系��根据星号前面的字符丄1�7 s[i] 是否相等，又可分为以下两种情况：

p[j-1] != s[i]：如果星号前丢�个字符匹配不上，星号匹配亄1�7 0 次，应忽略这两个字符，看 p[j-2] 咄1�7 s[i] 是否匹配〄1�7 这时 dp[i][j] = dp[i][j-2]〄1�7

p[j-1] == s[i] or p[j-1] == '.':星号前面的字符可以与 s[i] 匹配，这种情况下，星号可能匹配了前面的字符的 0 个，也可能匹配了前面字符的多个，当匹酄1�7 0 个时，如 ab 咄1�7 abb*，或耄1�7 ab 咄1�7 ab.* ，这时我们需要去掄1�7 p 中的 b* 戄1�7 .* 后进行比较，卄1�7 dp[i][j] = dp[i][j-2]；当匹配多个时，妄1�7 abbb 咄1�7 ab*，或耄1�7 abbb 咄1�7 a.*，我们需要将 s[i] 前面的与 p 重新比较，即 dp[i][j] = dp[i-1][j]

其他情况：以上两种情况把能匹配的都��虑全面了，扢�以其他情况为不匹配，卄1�7 dp[i][j] = False

将以上进行归纳得到状态转移方稄1�7

*/
class Solution{
public:
    bool isMatch(string s, string t){
        int sl = s.length(), tl = t.length();
        vector<vector<bool>> dp(sl + 1, vector<bool>(tl + 1, false));
        dp[0][0] = true;
        dp[0][1] = false;

        int i = 0, j = 0;
        //t[i] == '*'
        for (int c = 2; c <= tl; c++){
            i = c -1;
            if (t[i] == '*') dp[i][c] = dp[i][c - 2];
        }

        //
        for (int r = 1; r <= sl; r++){
            i = r - 1;
            for (int c = 1; c <= tl; c++){
                j = c - 1;
                if (s[i] == t[j] || t[j] == '*') dp[r][c] = dp[r - 1][c - 1];
                else if (t[j] == '.'){
                    if (s[i] == t[j - 1] || t[j - 1] == '*') dp[r][c] = dp[r - 1][c] || dp[r][c - 2];
                    else  dp[r][c] = dp[r][c - 2];
                }
            }
        }

        return dp[sl][tl];
    }
};

class Solution {
public:
    bool isMatch (string s, string p) {
        int m = s.length() + 1, n = p.length() + 1;

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        dp[0][0] = true;
        for (int j = 2; j < n; j += 2) {
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';

        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true;
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;

                }
                else {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] == true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;

                }
            }
        }

        return dp[m - 1][n - 1];
    }
};