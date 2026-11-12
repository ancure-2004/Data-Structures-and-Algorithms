#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(int mid, vector<int> arr, int k){
        int cntCows = 1;
        int last = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - last >= mid){
                cntCows++;
                last = arr[i];
            }
        }
        
        if(cntCows >= k) return true;
        
        return false;
    }
  
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int low = 0;
        int high = arr[n - 1] - arr[0];
        
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(mid, arr, k)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return high;
    }
};
