#include <iostream>
#include <stack>

using namespace std;

//鍓戞寚offer 30 鍖呭惈 main 鍑芥暟鐨勬爤
/*
瀹氫箟鏍堢殑鏁版嵁缁撴瀯锛岃鍦ㄨ绫诲瀷涓疄鐜颁竴涓兘澶熷緱鍒版爤鐨勬渶灏忓厓绱犵殑 min 鍑芥暟鍦ㄨ鏍堜腑锛�
璋冪敤 min銆乸ush 鍙� pop 鐨勬椂闂村鏉傚害閮芥槸 O(1)銆�

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 杩斿洖 -3.
minStack.pop();
minStack.top();      --> 杩斿洖 0.
minStack.min();   --> 杩斿洖 -2.
*/
//鍙屾爤 杈呭姪鏍堣В娉�
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

    void push(int x){//淇濊瘉鏈€涓婇潰鏄渶灏忓€硷紝鍚屾椂淇濊瘉 _min涔熸槸鏈€灏忓€�
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