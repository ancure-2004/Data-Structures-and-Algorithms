#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {2, 2, 3, 3, 4, 5};
    int n = 6;

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    bool ans = false;

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= sum/2; target++){

            bool not_take = dp[ind - 1][target];

            bool take = false;
            if(target >= arr[ind]){
                take = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = (not_take || take);
        }
    }

    if(sum % 2 == 0){
        ans = dp[n - 1][sum/2];
    }
    else{
        cout << false;
    }

    return 0;
}