#include<bits/stdc++.h>
using namespace std;

class myQueue {

  public:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int currsize;
  
    myQueue(int n) {
        arr.resize(n);
        front = -1;
        rear = -1;
        size = n;
        currsize = 0;
    }

    bool isEmpty() {
        if(currsize == 0) return true;
        
        return false;
    }

    bool isFull() {
        if(currsize == size) return true;
        
        return false;
    }

    void enqueue(int x) {
        if(isFull()) return ;
        
        if(isEmpty()) front = rear = 0;
        else rear++;
        
        arr[rear] = x;
        currsize++;
    }

    void dequeue() {
        if(isEmpty()) return ;
        
        if(front == rear){
            front = rear = -1;
        }
        else front++;
        
        currsize--;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
};