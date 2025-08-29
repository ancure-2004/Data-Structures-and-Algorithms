#include <bits/stdc++.h>
using namespace std;

int countSubset(int ind, int k, int arr[], vector<vector<int>> &dp){
    if(k == 0)
        return 1;

    if(ind == 0)
        return (arr[ind] == k);

    if(dp[ind][k] != -1){
        return dp[ind][k];
    }

    int notPick = countSubset(ind - 1, k, arr, dp);
    int pick = 0;
    if(arr[ind] <= k)
        pick = countSubset(ind - 1, k - arr[ind], arr, dp);

    return dp[ind][k] = pick + notPick;
}

int main() {

    int arr[] = {2, 3, 5, 16, 8, 10};
    int n = 6;
    int k = 10;

    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    int count = countSubset(n - 1, k, arr, dp);

    cout << count;

    return 0;
}