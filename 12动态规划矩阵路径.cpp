#include <iostream>
#include <vector>
#include <string>

using namespace std;

//剑指offer 12 矩阵中的路径 中等 动��规刄1�7 深度优先搜索
/*
请设计一个函数，用来判断在一个矩阵中是否存在丢�条包含某字符串所有字符的路径。路径可以从矩阵中的任意丢�格开始，
每一步可以在矩阵中向左��右、上、下移动丢�格��如果一条路径经过了矩阵的某丢�格，那么该路径不能再次进入该格子〄1�7
例如，在下面的1�73×4的矩阵中包含丢�条字符串“bfce”的路径（路径中的字母用加粗标出）��1�7

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第丢�个字符b占据了矩阵中的第丢�行第二个格子之后，路径不能再次进入这个格子��1�7

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

*/
class Solution{
public:
    bool exsit (vector<vector<int>> &board, string word){
        if(board.size() == 0) return false;// 

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i, j, 0)) return true; 
            }
        }

        return false;
    }
    bool dfs (vector<vector<int>> &board, string word, int i, int j, int length){
        if (i >= board.size() || j > board[0].size() || i < 0 || j < 0 || 
            length >= word.length() || word[length] != board[i][j]){// limit
                return false;
        }
        if (length == word.length() - 1 && word[length] == board[i][j]) return true;// find 

        int tmp = board[i][j];
        board[i][j] = '0'; // flag
        //iteration
        bool flag = dfs(board, word, i, j - 1, length + 1) || dfs(board, word, i, j + 1, length + 1) ||
                    dfs(board, word, i - 1, j, length + 1) || dfs(board, word, i + 1, j, length + 1);
        board[i][j] = tmp;// back

        return flag;
    }
};