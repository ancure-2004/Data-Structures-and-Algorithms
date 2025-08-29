#include <bits/stdc++.h>
using namespace std;

int unique_paths(int n, int m, vector<vector<int>> &dp){
    if(n == 0 && m == 0){
        return 1;
    }

    if(n < 0 || m < 0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    //UPWARD
    int UP = unique_paths(n - 1, m, dp);
    //lEFT
    int LEFT = unique_paths(n, m - 1, dp);

    return dp[n][m] = UP + LEFT;
}

int main() {
    int n = 3;
    int m = 3;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << unique_paths(n - 1, m - 1, dp);

    return 0;
}