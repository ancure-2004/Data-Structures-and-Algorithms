#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {1, 3, 2, 8, 4, 9};
    int n = 6;
    int fees = 2;

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
                //Substracting fees rest all are same
                int sellKaro = (prices[ind] - fees) + dp[ind + 1][1];
                int skipKaro = dp[ind + 1][0];
                profit = max(sellKaro, skipKaro);
            }

            dp[ind][buy] = profit;
        }
    }

    cout << dp[0][1];

    return 0;
}