#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    int price[] = {2, 5, 7, 8, 10};

    vector<vector<int>> dp(n, vector<int> (n + 1, 0));

    for(int rod = 0; rod <= n; rod++){
        dp[0][rod] = rod * price[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int rod = 0; rod <= n; rod++){
            int notPick = dp[ind - 1][rod];
            int pick = INT_MIN;
            if(ind + 1 <= rod){
                pick = price[ind] + dp[ind][rod - (ind + 1)];
            }

            dp[ind][rod] = max(pick, notPick);
        }
    }

    cout << dp[n - 1][n];

    return 0;
}