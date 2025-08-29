#include <bits/stdc++.h>
using namespace std;

int main() {

    int coins[] = {1, 2, 3};
    int n = 3;
    int target = 7;

    vector<vector<int>> dp(n, vector<int> (target + 1, 0));

    for(int i = 0; i <= target; i++){
        if(i % coins[0] == 0) dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9;
    }

    for(int ind = 1; ind < n; ind++){
        for(int t = 0; t <= target; t++){
            int notTake = 0 + dp[ind - 1][t];
            int take = 1e9;
            if(coins[ind] <= t){
                take = 1 + dp[ind][t - coins[ind]];
                
            }
            dp[ind][t] = min(take, notTake);
        }
    }  

    cout << dp[n - 1][target];

    return 0;
}