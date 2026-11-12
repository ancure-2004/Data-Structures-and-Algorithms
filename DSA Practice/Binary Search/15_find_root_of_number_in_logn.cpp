#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        
        int low = 1;
        int end = n/2;
        
        int ans = 1;
        
        while(low <= end){
            int mid = low + (end - low)/2;
            
            if(mid * mid <= n){
                ans = mid;
                low = mid + 1;
            }
            
            else{
                end = mid - 1;
            }
        }
        
        return ans;
    }
};