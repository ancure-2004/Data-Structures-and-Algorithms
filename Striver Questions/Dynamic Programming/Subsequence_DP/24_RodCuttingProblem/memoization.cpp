#include <bits/stdc++.h>
using namespace std;

int cutting(int ind, int rod, int price[], vector<vector<int>> &dp){
    if(ind == 0){
        return rod * price[0];
    }

    if(dp[ind][rod] != -1){
        return dp[ind][rod];
    }

    int notPick = cutting(ind - 1, rod, price, dp);
    int pick = INT_MIN;
    if(ind + 1 <= rod){
        pick = price[ind] + cutting(ind, rod - (ind + 1), price, dp);
    }

    return dp[ind][rod] = max(pick, notPick);
}

int main() {

    int n = 5;
    int price[] = {2, 5, 7, 8, 10};

    vector<vector<int>> dp(n, vector<int> (n + 1, -1));

    int money = cutting(n - 1, n, price, dp);
    cout << money;

    return 0;
}