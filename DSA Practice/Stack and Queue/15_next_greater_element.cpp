#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        unordered_map<int, int> nextGreater;
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }

            if(st.empty()){
                nextGreater[nums2[i]] = -1;
            }
            else{
                nextGreater[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        int m = nums1.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            ans[i] = nextGreater[nums1[i]];
        }

        return ans;
    }
};