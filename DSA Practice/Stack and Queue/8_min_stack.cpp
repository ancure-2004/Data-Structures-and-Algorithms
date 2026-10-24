#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {
    }
    
    void push(int value) {
        if(s.empty()){
            s.push({value, value});
        }
        else{
            s.push({value, min(value, s.top().second)});
        }
    }
    
    void pop() {
        if(s.empty()) return;
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top().first;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */