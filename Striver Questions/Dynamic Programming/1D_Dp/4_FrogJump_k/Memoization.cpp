#include <bits/stdc++.h>
using namespace std;

int k_jumps(int n, int k, int height[], vector<int> &dp){
    if(n == 0) return 0;

    if(dp[n] != -1)
        return dp[n];

    int min_steps = INT_MAX;
    for(int i = 1; i <= k; i++){
        int jump = INT_MAX;
        if(n - i >= 0)
            jump = abs(height[n] - height[n - i]) + k_jumps(n - i, k, height, dp);
        min_steps = min(min_steps, jump);
    }

    return dp[n] = min_steps;
}

int main() {

    int n = 4;
    int height[] = { 10, 20, 30 , 40 };
    vector<int> dp(n + 1, -1);
    int k = 4;

    cout << k_jumps(n - 1, k, height, dp);

    return 0;
}