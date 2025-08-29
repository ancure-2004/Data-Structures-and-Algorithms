#include <bits/stdc++.h>
using namespace std;

int counting(int ind, int target, int coins[], vector<vector<int>>& dp){
    if(ind == 0)
    if(target % coins[ind] == 0) return target/coins[ind];
    else return 1e9;

    if(dp[ind][target] != -1)
        return dp[ind][target];

    int notTake = 0 + counting(ind - 1, target, coins, dp);
    int take = 1e9;
    if(coins[ind] <= target){
        take = 1 + counting(ind, target - coins[ind], coins, dp);
        
    }
    return dp[ind][target] = min(take, notTake);
}

int main() {

    int coins[] = {1, 2, 3};
    int n = 3;
    int target = 7;

    vector<vector<int>> dp(n, vector<int> (target + 1, -1));

    int no_of_coins = counting(n - 1, target, coins, dp);

    cout << no_of_coins;  

    return 0;
}