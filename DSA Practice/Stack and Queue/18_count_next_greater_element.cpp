#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = arr.size();
        int m = indices.size();

        vector<int> nextGreater(m);
        
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = indices[i] + 1; j < n; j++){
                if(arr[j] > arr[indices[i]]) cnt++;
            }
            nextGreater[i] = cnt;
        }
        
        return nextGreater;
    }
};