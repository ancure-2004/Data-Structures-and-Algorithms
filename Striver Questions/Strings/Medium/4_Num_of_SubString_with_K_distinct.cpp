#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int substrLessthanK(string s, int k){
        
        if(k == 0) return 0;
        
        int n = s.size();
        int cnt = 0, distinct = 0;
        int l = 0, r = 0;
        vector<int> mpp(26, 0);
        while(r < n){
            int numR = s[r] - 'a' ;
            if(mpp[numR] == 0) distinct++;
            mpp[numR]++;
            while(distinct > k){
                int numL = s[l] - 'a';
                mpp[numL]--;
                if(mpp[numL] == 0){
                    distinct--;
                }
                l = l + 1;
            }
            cnt += (r - l + 1);
            r = r + 1;
        }
        
        return cnt;
    }
  
    int countSubstr(string& s, int k) {
        
        int LessThanK = substrLessthanK(s, k);
        int oneLessThanK = substrLessthanK(s, k - 1);
        
        return LessThanK - oneLessThanK;
    }
};