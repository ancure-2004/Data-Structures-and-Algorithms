#include <bits/stdc++.h>
using namespace std;

int trading(int ind, int buy, int cap, int prices[], int n, vector<vector<vector<int>>> &dp){

    if(cap == 0) return 0;
    if(ind == n) return 0;

    if(dp[ind][buy][cap] != -1){
        return dp[ind][buy][cap];
    }


    if(buy){
        int buyKaro = -prices[ind] + trading(ind + 1, 0, cap, prices, n, dp);
        int skipKaro = trading(ind + 1, 1, cap, prices, n, dp);
        return dp[ind][buy][cap] = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[ind] + trading(ind + 1, 1, cap - 1, prices, n, dp);
        int skipKaro = trading(ind + 1, 0, cap, prices, n, dp);
        return dp[ind][buy][cap] = max(sellKaro, skipKaro);
    }
}

int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = 8;

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

    int profit = trading(0, 1, 2, prices, n, dp);
    cout << profit;

    return 0;
}