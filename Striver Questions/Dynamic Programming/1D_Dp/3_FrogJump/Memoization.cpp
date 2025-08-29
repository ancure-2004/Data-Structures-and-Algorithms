#include <bits/stdc++.h>
using namespace std;

//Memoization
int jumps1(int n, int height[], vector<int> &dp){

    if(n == 0) return 0;

    if(dp[n] != -1){
        return dp[n];
    }

    int left = abs(height[n] - height[n - 1]) + jumps1(n - 1, height, dp);

    int right = INT_MAX;
    if(n > 1)
        right = abs(height[n] - height[n - 2]) + jumps1(n - 2, height, dp);

    return dp[n] = min(left, right);
}

int main(){

    int n = 4;
    vector<int> dp(n + 1, -1);

    int height[] = {10, 20, 30, 10};
    cout << jumps1(n - 1, height, dp);

    return 0;
}