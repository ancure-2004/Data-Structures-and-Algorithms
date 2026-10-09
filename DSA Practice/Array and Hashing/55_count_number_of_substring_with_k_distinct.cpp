#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        int n = s.size();
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            unordered_map<int, int> hash;
            
            for(int j = i; j < n; j++){
                hash[s[j]]++;
                if(hash.size() > k){
                    break;
                }
                if(hash.size() == k){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};


//Optimal Solution
class Solution {
  public:
    
    int countSubstrlessk(string s, int k){
        int n = s.size();
        
        int cnt = 0;
        int mpp[26] = {0};
        int l = 0;
        int r = 0;
        int distinct = 0;
        
        while(r < n){
            if(mpp[s[r] - 'a'] == 0) distinct++;
            
            mpp[s[r] - 'a']++;
            
            while(distinct > k){
                mpp[s[l] - 'a']--;
                if(mpp[s[l] - 'a'] == 0) distinct--;
                l = l + 1;
            }
            
            cnt += r - l + 1;
            r = r + 1;
        }
        
        return cnt;
    }
  
  
    int countSubstr(string& s, int k) {
        // code here
        int n = s.size();
        
        return countSubstrlessk(s, k) - countSubstrlessk(s, k - 1);
    }
};