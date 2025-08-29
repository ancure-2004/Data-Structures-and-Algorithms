#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

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

    return dp[ind][k] = (pick + notPick) % mod;
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int d = 2;

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> ((totalSum - d)/2 + 1, -1));

    if(totalSum - d < 0 || (totalSum - d) % 2) return false;

    int count = countSubset(n - 1, (totalSum - d) / 2, arr, dp);

    cout << count;

    return 0;
}