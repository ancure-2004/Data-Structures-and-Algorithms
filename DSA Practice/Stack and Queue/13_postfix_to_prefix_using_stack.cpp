#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string s) {
        // code here
        int n = s.size();

        stack<string> st;

        int i = 0;
        while(i < n){
            if(
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')
            ){
                st.push(string(1, s[i]));
            }

            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string expression = s[i] + t2 + t1;
                st.push(expression);
            }

            i++;
        }

        return st.top();
    }
};