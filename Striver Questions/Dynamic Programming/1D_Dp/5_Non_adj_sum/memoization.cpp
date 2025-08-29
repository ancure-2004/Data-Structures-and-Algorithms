#include <bits/stdc++.h>
using namespace std;

int non_adjacent_sum(int n, int arr[], vector<int> &dp){

    if(n == 0) return arr[n];
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    int pick = arr[n] + non_adjacent_sum(n - 2, arr, dp);
    int notPick = 0 + non_adjacent_sum(n - 1, arr, dp);

    return dp[n] = max(pick, notPick);
}

int main() {

    int arr[] = {2, 1, 4, 9};
    int n = 4;
    vector<int> dp(n + 1, -1);

    cout << non_adjacent_sum(n - 1, arr, dp);

    return 0;
}