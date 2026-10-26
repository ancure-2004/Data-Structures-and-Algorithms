#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
class Solution {
public:
    vector<int> findNse(vector<int> &arr, int n){
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findpsee(vector<int> &arr, int n){
        vector<int> psee(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<int> nse = findNse(arr, n);
        vector<int> psee = findpsee(arr, n);

        int total = 0;
        for(int i = 0; i < n; i++){
            int left = nse[i] - i;
            int right = i - psee[i];

            total = (total + (1LL * left * right * arr[i]) % mod) % mod;
        }

        return total;
    }
};