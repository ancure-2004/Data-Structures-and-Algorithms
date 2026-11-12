#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long nTime(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans * mid;
            
            if(ans > m) return m + 1;
        }
        
        return ans;
    }
  
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0) return 0;
        
        int low = 1;
        int end = m;


        while(low <= end){
            int mid = low + (end - low)/2;
            
            if(nTime(mid, n, m) == m){
                return mid;
            }
            
            else if(nTime(mid, n, m) < m){
                low = mid + 1;
            }

            else{
                end = mid - 1;
            }
        }

        return -1;
    }
};