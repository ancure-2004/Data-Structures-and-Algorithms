#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 4;
    int height[] = { 10, 20, 30 , 40 };
    vector<int> dp(n + 1, 0);
    int k = 4;

    for(int i = 1; i < n; i++){
        int min_steps = INT_MAX;
        for(int j = 1; j <= k; j++){
            int jump = INT_MAX;
            if(i - j >= 0)
                jump = abs(height[i] - height[i - j]) + dp[i - j];
            
            min_steps = min(min_steps, jump);
        }
        dp[i] = min_steps;
    }
    
    cout<< dp[n - 1];

    return 0;
}