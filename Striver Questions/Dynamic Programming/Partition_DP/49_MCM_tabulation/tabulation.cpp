#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {10, 30, 5, 60};
    int n = 4;

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i < n; i++){
        dp[i][i] = 0;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    cout << dp[1][n - 1];

    return 0;
}