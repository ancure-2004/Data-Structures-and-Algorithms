#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    
    int xr = 0;
    int cnt = 0;
    unordered_map<int, int> hash;
    hash[xr]++;
    for(int i = 0; i < n; i++){
        xr = xr ^ A[i];
        int x = xr ^ B;
        cnt += hash[x];
        hash[xr]++;
    }
    
    return cnt;

}
