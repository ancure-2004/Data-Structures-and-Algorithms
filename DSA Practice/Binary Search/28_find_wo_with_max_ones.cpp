#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerbound(vector<int> arr, int m, int i){
        int low = 0;
        int high = m - 1;
        int ans = m;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] >= i){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int cntMax = 0;
        int index = -1;
        for(int i = 0; i < n; i++){
            int cnt = m - lowerbound(arr[i], m, 1);
            
            if(cnt > cntMax){
                cntMax = cnt;
                index = i;
            }
        }
        
        return index;
    }
};