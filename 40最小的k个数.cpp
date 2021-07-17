#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//剑指offer 40 最小的 k 个数
/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

输入：arr = [0,1,2,1], k = 1
输出：[0]

方法二：堆
思路和算法

我们用一个大根堆实时维护数组的前 k 小值。首先将前 k 个数插入大根堆中，
随后从第 k+1个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，
就把堆顶的数弹出，再插入当前遍历到的数。
最后将大根堆里的数存入数组返回即可。
在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，
我们可以这么做。而 Python 语言中的对为小根堆，
因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k 小值。

*/
class Solution{
public:
    vector<int> getLeastNumbers(vector<int> &nums, int k){
        //..排序
        sort(nums.begin(), nums.end());
        return vector<int>(nums.begin(), nums.begin() + k);

        //..堆
        vector<int> res(k, 0);
        if (k == 0) return res;

        priority_queue<int> heap;
        for (int i = 0; i < k; i++) heap.push(nums[i]);
        for (int i = k; i < nums.size(); i++){
            if (heap.top() > nums[i]){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        for (int i = 0; i < k; i++){
            res.push_back(heap.top());
            heap.pop();
        } 
        return res;
    }
};