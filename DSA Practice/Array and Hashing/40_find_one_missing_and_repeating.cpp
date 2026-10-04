#include<bits/stdc++.h>
using namespace std;

//Mathematical Solution
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        long long sn = 1LL* n * (n+1) / 2;
        long long s2n = 1LL * n * (n+1) * (2*n+1)/6;
        long long s = 0;
        long long s2 = 0;
        
        for(int i = 0; i < n; i++){
            s = s + arr[i];
            s2 += 1LL * arr[i] * arr[i];
        }
        
        long long VAL1 = s-sn;
        long long VAL2 = s2-s2n;
        
        VAL2 = VAL2/VAL1;
        
        long long x = VAL1 + (VAL2 - VAL1)/2;
        long long y = x - VAL1;
        
        return {x, y};
    }
};


//Bit manipulation solution
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }
        
        int bitNo = 0;
        while(1){
            if((xr & (1 << bitNo)) != 0){
                break;
            }
            bitNo++;
        }
        
        int zero = 0;
        int one = 0;
        for(int i = 0; i < n; i++){
            if((arr[i] & (1 << bitNo)) != 0){
                one = one ^ arr[i];
            }
            else{
                zero = zero ^ arr[i];
            }
        }
        
        for(int i = 1; i <= n; i++){
            if((i & (1 << bitNo)) != 0){
                one = one ^ i;
            }
            else{
                zero = zero ^ i;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == zero){
                cnt++;
            }
        }
        if(cnt == 2) return {zero, one};
        
        return {one, zero};
    }
};