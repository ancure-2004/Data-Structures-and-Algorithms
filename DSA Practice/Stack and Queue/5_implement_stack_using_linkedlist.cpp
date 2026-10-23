#include<bits/stdc++.h>
using namespace std;

//Structure of linked list Node

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


//Naive Approach
class myStack {
    Node* top;
    Node* head;
    int currSize;
  public:
    myStack() {
        head = nullptr;
        top = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0 ? true : false;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        
        if(currSize == 0){
            top = newNode;
            head = newNode;
        }
        else{
            top -> next = newNode;
            top = top -> next;
        }
        
        currSize++;
    }

    void pop() {
        if(currSize == 0) return;
        if(currSize == 1){
            top = nullptr;
            head = nullptr;
            currSize--;
            return;
        }
        
        Node* temp = head;
        
        while(temp -> next != top){
            temp = temp -> next;
        }
        
        Node* delNode = top;
        temp -> next = nullptr;
        top = temp;
        delete delNode;
        
        currSize--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(currSize == 0){
            return -1;
        }
        
        return top -> data;
    }

    int size() {
        return currSize;
    }
};


//Optimal Approach
class myStack {
    Node* top;
    int currSize;
  public:
    myStack() {
        top = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0 ? true : false;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        
        newNode -> next = top;
        top = newNode;
        
        currSize++;
    }

    void pop() {
        Node* delNode = top;
        top = top -> next;
        delete delNode;
        
        currSize--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(currSize == 0){
            return -1;
        }
        
        return top -> data;
    }

    int size() {
        return currSize;
    }
};