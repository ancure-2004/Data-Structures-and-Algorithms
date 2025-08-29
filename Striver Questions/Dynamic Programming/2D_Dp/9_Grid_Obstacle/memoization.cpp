#include <bits/stdc++.h>
using namespace std;

int unique_paths(int n, int m, vector<vector<int>> &dp, int arr[][3]){
    if(n >= 0 && m >= 0 && arr[n][m] == -1){
        return 0;
    }
    if(n == 0 && m == 0){
        return 1;
    }
    if(n < 0 || m < 0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    //UPWARD
    int UP = unique_paths(n - 1, m, dp, arr);
    //lEFT
    int LEFT = unique_paths(n, m - 1, dp, arr);

    return dp[n][m] = UP + LEFT;
}

int main() {
    int n = 3;
    int m = 3;
    int arr[3][3] = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << unique_paths(n - 1, m - 1, dp, arr);

    return 0;
}