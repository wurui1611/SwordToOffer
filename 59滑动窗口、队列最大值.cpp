#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//..剑指offer 59-I 滑动窗口的最大值
/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        if (nums.size() == 0) return {};

        vector<int> res;
        for (int i = 0; i <= nums.size() - k; i++){
            int maxNum = nums[i];
            for (int j = i; j < k; j++){
                maxNum = max(maxNum, nums[j]);
            }
            res.push_back(maxNum);
        }

        return res;
    }
};

//..剑指offer 59-II 队列的最大值 中等
/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 
的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
*/
class Solution{
private:
    queue<int> q;
    deque<int> d;
public:
    void MaxQueue(){}

    int maxvalue(){
        if (d.empty()) return -1;
        return d.front();
    }

    void push_back(int value){
        while (!d.empty() && d.back() < value) d.pop_back();
        d.push_back(value);
        q.push(value);
    }

    int pop_back(){
        if (q.empty()) return -1;

        int res = q.front();
        if (res == d.front()) d.pop_front();
        q.pop();

        return res;
    }
};