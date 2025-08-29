#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 3};
    int n = 3;
    int target = 4;

    vector<vector<int>> dp(n, vector<int> (target + 1, 0));

    for(int  tar = 0; tar <= target; tar++){
        if(tar % arr[0] == 0) dp[0][tar] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= target; tar++){
            int notPick =  dp[ind - 1][tar]; 
            int pick = 0;
            if(arr[ind] <= tar){
                pick = dp[ind][tar - arr[ind]];
            }

            dp[ind][tar] = pick + notPick;
        }
    }

    cout << dp[n - 1][target];

    return 0;
}