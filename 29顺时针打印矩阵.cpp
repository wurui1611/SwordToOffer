#include <iostream>
#include <vector>

using namespace std;

//剑指offer 29 顺时针打印矩阵
/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/
class SOlution{
public:
    vector<int> printMatrix(vector<vector<int>> &matrix){
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};// 边界条件

        vector<int> res;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;//定义上下左右

        while(true){
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);//右移
            top++;
            if(top > bottom) break;//边界条件

            for(int j = top; j <= bottom; j++) res.push_back(matrix[j][right]);//下移
            right--;
            if(right < left) break;//边界条件

            for(int k = right; k >= left; k--) res.push_back(matrix[bottom][k]);//左移
            bottom--;
            if(bottom < top) break;//边界条件

            for(int l = bottom; l >= top; l--) res.push_back(matrix[l][left]);//上移
            left++;
            if(left > right) break;//边界条件
        }

        return res;
    }
};