#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> s;
    queue<int> s1;
    int topElement;

    MyStack() {
        topElement = 0;
    }
    
    void push(int x) {
        s.push(x);
        topElement = x;
    }
    
    int pop() {
        int t = topElement;
        while(s.size() > 1){
            int element = s.front();
            s.pop();
            s1.push(element);
            topElement = element;
        }

        int answer = s.front();
        s.pop();

        swap(s, s1);

        return answer;
    }
    
    int top() {
        if(s.empty()) return -1;

        return topElement;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */