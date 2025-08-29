#include <bits/stdc++.h>
using namespace std;

int trading(int ind, int buy, int prices[], int n, vector<vector<int>> &dp){
    if(ind == n){
        return 0;
    }

    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }

    int profit = 0;

    if(buy){
        int buyKaro = -prices[ind] + trading(ind + 1, 0, prices, n, dp);
        int skipKaro = trading(ind + 1, 1, prices, n, dp);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[ind] + trading(ind + 1, 1, prices, n, dp);
        int skipKaro = trading(ind + 1, 0, prices, n, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[ind][buy] = profit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    vector<vector<int>> dp(n, vector<int> (2, -1));

    int profit = trading(0, 1, prices, n, dp);
    cout << profit;

    return 0;
}