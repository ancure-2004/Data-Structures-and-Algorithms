#include<bits/stdc++.h>
using namespace std;

class myStack {
  public:
    
    vector<int> arr;
    int top;
    int size;
  
    myStack(int n) {
        arr.resize(n);
        top = -1;
        size = n - 1;
    }

    bool isEmpty() {
        if(top == -1){
            return true;
        }
        
        return false;
    }

    bool isFull() {
        if(top ==  size){
            return true;
        }
        
        return false;
    }

    void push(int x) {
        
        if(top == size) return;
        
        top ++;
        arr[top] = x;
    }

    void pop() {
        if(top == -1) return;
        top--;
    }

    int peek() {
        if(top == -1) return -1;
        return arr[top];
    }
};