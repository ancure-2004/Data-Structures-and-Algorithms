#include <bits/stdc++.h>
using namespace std;

int MCM(int i, int j, int arr[], vector<vector<int>> &dp){
    if(i == j) return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM(i, k, arr, dp) + MCM(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int main(){

    int arr[] = {10, 30, 5, 60};
    int n = 4;

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

    int product = MCM(1, n-1, arr, dp);
    cout << product;

    return 0;
}