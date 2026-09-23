#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<long, long> sumMap;
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == k){
                maxLen = max(maxLen, i + 1);
            }
            
            long long rem = sum - k;
            
            if(sumMap.find(rem) != sumMap.end()){
                int len = i - sumMap[rem];
                maxLen = max(maxLen, len);
            }
            
            if(sumMap.find(sum) == sumMap.end()){
                sumMap[sum] = i;
            }
        }
        
        return maxLen;
        
    }
};