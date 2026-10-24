#include<bits/stdc++.h>
using namespace std;

//Naive Approach
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<int> validation;

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                validation.push(s[i]);
            }
            else if(!validation.empty()){
                if(s[i] == ')' && validation.top() == '(') validation.pop();
                else if(s[i] == '}' && validation.top() == '{') validation.pop();
                else if(s[i] == ']' && validation.top() == '[') validation.pop();
                else validation.push(s[i]);
            }
            else validation.push(s[i]);
        }

        return validation.empty();
    }
};

//Structured Way of coding
class Solution {
public:
    bool isValid(string s) {

        if(s.size() < 2) return false;

        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                int top = st.top();
                int c = s[i];
                if( (top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}'))
                {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};