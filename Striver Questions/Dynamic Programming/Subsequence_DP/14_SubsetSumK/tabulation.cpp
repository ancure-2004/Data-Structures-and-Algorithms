#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int k = 6;

    vector<vector<bool>> dp(n + 1, vector<bool> (k + 1, false));

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){

            bool not_take = dp[ind - 1][target];

            bool take = false;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = (not_take || take);
        }
    }

    cout << dp[n - 1][k];

    return 0;
}