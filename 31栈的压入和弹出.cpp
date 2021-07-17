#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//剑指offer 31 栈的压入和弹出
/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1


输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。

分析：
解题思路
思路很简单，我们尝试按照 popped 中的顺序模拟一下出栈操作，如果符合则返回 true，否则返回 false。
这里用到的贪心法则是如果栈顶元素等于 popped 序列中下一个要 pop 的值，则应立刻将该值 pop 出来。

我们使用一个栈 st 来模拟该操作。将 pushed 数组中的每个数依次入栈，
同时判断这个数是不是 popped 数组中下一个要 pop 的值，如果是就把它 pop 出来。最后检查栈是否为空。

算法
初始化栈 stack，j = 0；
遍历 pushed 中的元素 x；
当 j < popped.size() 且栈顶元素等于 popped[j]：
弹出栈顶元素；
j += 1；
如果栈为空，返回 True，否则返回 False。

*/
class Solution{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped){
        stack<int> _stack;
        int j = 0;

        for (int i = 0; i < pushed.size(); i++){
            _stack.push(pushed[i]);//先把pushed里面加入栈中
            while (!_stack.empty() && j < popped.size() && _stack.top() == popped[j]){//和popped中元素比较
                _stack.pop();
                j++;
            }
        }

        return _stack.empty();
    }
};