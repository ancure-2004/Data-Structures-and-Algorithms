#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){

            int profit = 0;
            if(buy){
                int buyKaro = -prices[ind] + dp[ind + 1][0];
                int skipKaro = dp[ind + 1][1];
                profit = max(buyKaro, skipKaro);
            }
            else{
                int sellKaro = prices[ind] + dp[ind + 1][1];
                int skipKaro = dp[ind + 1][0];
                profit = max(sellKaro, skipKaro);
            }

            dp[ind][buy] = profit;
        }
    }

    cout << dp[0][1];

    return 0;
}