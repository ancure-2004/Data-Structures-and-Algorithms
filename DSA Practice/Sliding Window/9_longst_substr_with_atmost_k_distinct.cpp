#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        
        int l = 0;
        int r = 0;
        int maxLen = 0;
        
        unordered_map<int, int> hash;
        
        while(r < n){
            hash[s[r] - 'a']++;
            
            if(hash.size() > k){
                hash[s[l] - 'a']--;
                if(hash[s[l] - 'a'] == 0) hash.erase(s[l] - 'a');
                l++;
            }
            
            if(hash.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        if(hash.size() < k) return -1;
        
        return maxLen;
    }
};