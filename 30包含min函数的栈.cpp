#include <iostream>
#include <stack>

using namespace std;

//剑指offer 30 包含 main 函数的栈
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中＄1�7
调用 min、push 叄1�7 pop 的时间复杂度都是 O(1)〄1�7

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
*/
//双栈 辅助栈解泄1�7
class Solution{
private:
    stack<int> s;
    stack<int> s_min;
public:
    void MinMain(){}

    void push(int x){
        s.push(x);

        if (s_min.empty()){
            if (x > s_min.top()){
                s_min.push(s_min.top());
            }
            else {
                s_min.push(x);
            }
        }
    }

    void pop(){
        s.pop();
        s_min.pop();
    }

    int top(){
        return s.top();
    }

    int getmin(){
        return s_min.top();
    }
};

class SOlution{
private:
    stack<int> _stack;
    int _min = INT32_MAX;
public:
    void MinMain(){

    }

    void push(int x){//保证朢�上面是最小��，同时保证 _min也是朢�小��1�7
        if(_min >= x){
            if(!_stack.empty()) _stack.push(_min);
            _min = x;
        }

        _stack.push(x);
    }

    void pop(){
        if(_stack.empty()) return;
        if(_stack.size() == 1) _min = INT32_MAX;
        else if(_min == _stack.top()){
            _stack.pop();
            _min = _stack.top();
        }
        _stack.pop();
    }

    int top(){
        return _stack.top();
    }

    int getMin(){
        return _min;
    }
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
};

class MinStack{
private:
    stack<int> s;
    stack<int> s_min;

public:
    void push(int x) {
        if (s_min.empty() || s_min.top() >= x) {
            s_min.push(x);

        }

        s.push(x);

    }

    void pop() {
        if (s_min.top() == s.top()) {
            s_min.pop();

        }

        s.pop();
    }

    int top() {
        return s.top();

    }

    int get_min() {
        return s_min.top();

    }
};