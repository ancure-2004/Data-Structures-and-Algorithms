#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    int front;

    MyQueue() {
        front = 0;
    }
    
    void push(int x) {
        if(s1.empty()) front = x; 
        s1.push(x);
    }
    
    int pop() {

        if(s1.empty()) return -1;

        if(s1.size() == 1){
            int ans = front;
            s1.pop();
            front = 0;
            return ans;
        }

        while(s1.size() > 1){
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }

        int answer = s1.top();
        s1.pop();

        front = s2.top();

        while(!s2.empty()){
            int element = s2.top();
            s2.pop();
            s1.push(element);
        }

        return answer;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */