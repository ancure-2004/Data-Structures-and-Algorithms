#include<bits/stdc++.h>
using namespace std;

//Naive Approach
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = findNse(heights, n);
        vector<int> pse = findpsee(heights, n);

        if(n == 1) return heights[0];

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;
    }
};


//Optimal Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;

            int element = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }
};