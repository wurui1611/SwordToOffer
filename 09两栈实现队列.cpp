#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

//剑指offer 09 用两个栈 实现 队列
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/
class Solution{
private:
    stack<int> stack1;//..主栈
    stack<int> stack2;//..辅栈

public:
    void CQueue(){}

    void appendTail(int value){
        stack1.push(value);//..主栈加入值
    }

    int deleteHead(){//..将主栈的值传入辅栈， 主栈底部的值也就是队列的头部的值
        if(stack1.empty()) return -1;

        while(!stack1.empty()){// 1 -> 2
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        //delete Head
        int res = stack2.top();// 记录删除的元素
        stack2.pop();// 弹出删除的元素

        while(!stack2.empty()){// 2 -> 1 将弹出后的元素返回到 栈1中
            int tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }

        return res;// 返回删除的元素
    }
};