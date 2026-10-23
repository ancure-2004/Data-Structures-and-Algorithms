#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    Node* start;
    Node* end;
    int currSize;
  public:
    myQueue() {
        // Initialize your data members
        start = nullptr;
        end = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0 ? true : false;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if(start == nullptr){
            start = end = temp;
        }
        else{
            end -> next = temp;
            end = temp;
        }
        currSize++;
    }

    void dequeue() {
        if(start == nullptr) return;
        
        Node* temp = start;
        start = start -> next;
        delete temp;
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(start == nullptr) return -1;
        return start -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return currSize;
    }
};
