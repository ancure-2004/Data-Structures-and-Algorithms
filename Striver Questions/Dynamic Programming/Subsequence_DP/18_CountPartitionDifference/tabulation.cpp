#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int d = 1;

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }

    if(totalSum - d < 0 || (totalSum - d) % 2) return false;

    int k = (totalSum - d) / 2;

    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k; sum++){
            int notPick = dp[ind - 1][sum];
            int pick = 0;
            if(arr[ind] <= sum)
                pick = dp[ind - 1][sum - arr[ind]];

            dp[ind][sum] = pick + notPick;
        }
    }

    cout << dp[n - 1][k];

    return 0;
}