#include<bits/stdc++.h>
using namespace std;

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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNse(arr, n);
        vector<int> psee = findpsee(arr, n);

        long long total = 0;
        for(int i = 0; i < n; i++){
            int left = nse[i] - i;
            int right = i - psee[i];

            total = (total + (1LL * left * right * arr[i]));
        }

        return total;
    }

        vector<int> findNge(vector<int> &arr, int n){
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    vector<int> findpgee(vector<int> &arr, int n){
        vector<int> pgee(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pgee;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();

        vector<int> nge = findNge(arr, n);
        vector<int> pgee = findpgee(arr, n);

        long long total = 0;
        for(int i = 0; i < n; i++){
            int left = nge[i] - i;
            int right = i - pgee[i];

            total = (total + (1LL * left * right * arr[i]));
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long maxi = sumSubarrayMax(nums);
        long long mini = sumSubarrayMins(nums);

        return maxi - mini;
    }
};