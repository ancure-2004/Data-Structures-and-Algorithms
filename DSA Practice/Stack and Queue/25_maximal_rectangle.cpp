#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestHistoArea(vector<int> heights){
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

        while(!st.empty()) {
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea,
                heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> bars(m, 0);

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    bars[j] = 0;
                }
                 
                if(matrix[i][j] == '1'){
                    bars[j] += (matrix[i][j] - '0');
                }
            }

            int currentArea = largestHistoArea(bars);
            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }
};