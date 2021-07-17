#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//..剑指offer 41 数据流中的中位数 困难
/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]

lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个 出现的位置。
功能：函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置.

注意：如果所有元素都小于val，则返回last的位置，且last的位置是越界的！！

upper_bound(起始地址，结束地址，要查找的数值) 返回的是数值 最后一个 出现的位置。
功能：函数upper_bound()返回的在前闭后开区间查找的关键字的上界，返回大于val的第一个元素位置

注意：返回查找元素的最后一个可安插位置，也就是“元素值>查找值”的第一个元素的位置。同样，如果val大于数组中全部元素，返回的是last。(注意：数组下标越界)


binary_search(起始地址，结束地址，要查找的数值) 返回的是是否存在这么一个数，是一个bool值。

*/
class Solution{
private:
    vector<int> nums;
public:
    void Median(){}

    void addNum(int num){
        if (nums.size() == 0) nums.push_back(num);
        else nums.insert(lower_bound(nums.begin(), nums.end(), num), num);// 二分查找排序
    }

    double getMedian(){
        int n = nums.size();

        return n & 1 ? nums[n / 2] : (nums[n / 2 - 1] + nums[n / 2]) * 0.5;
    }
};