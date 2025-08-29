#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = 8;

    int k = 2;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));

    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= k; cap++){

                if(buy){
                    int buyKaro = -prices[ind] + dp[ind + 1][0][cap];
                    int skipKaro = dp[ind + 1][1][cap];
                    dp[ind][buy][cap] = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[ind] + dp[ind + 1][1][cap - 1];
                    int skipKaro = dp[ind + 1][0][cap];
                    dp[ind][buy][cap] = max(sellKaro, skipKaro);
                }
            }
        }
    }

    cout << dp[0][1][2];

    return 0;
}