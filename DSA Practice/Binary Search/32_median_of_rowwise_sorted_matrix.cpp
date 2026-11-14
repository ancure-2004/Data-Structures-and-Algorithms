#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int upperbound(vector<int> mat, int x){
        int low = 0;
        int high = mat.size() - 1;
        
        int ans = mat.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(mat[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
  
    int blackbox(vector<vector<int>> mat, int mid){
        int cnt = 0;
        
        for(int i = 0; i < mat.size(); i++){
            cnt += upperbound(mat[i], mid);
        }
        
        return cnt;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i = 0; i < n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        
        int req = (n * m)/2;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int smallerThan = blackbox(mat,  mid);
            
            if(smallerThan <= req){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return low;
    }
};
