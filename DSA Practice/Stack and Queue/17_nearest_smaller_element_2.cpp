#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();
        
    vector<int> prevSmall(n);
    stack<int> st;
        
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= A[i]){
            st.pop();
        }
            
        if(st.empty()){
            prevSmall[i] = -1;
        }
        else{
            prevSmall[i] = st.top();
        }
            
        st.push(A[i]);
    }
        
    return prevSmall; 
}
