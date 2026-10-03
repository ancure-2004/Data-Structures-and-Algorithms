#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> hash;
        
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == 0){
                maxLen = i + 1;
            }
            else{
                if(hash.find(sum) != hash.end()){
                    int len = i - hash[sum];
                    maxLen = max(maxLen, len);
                }
                else hash[sum] = i;
            }
        }
        
        return maxLen;
    }
};