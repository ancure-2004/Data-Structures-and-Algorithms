#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {3, 9, 7, 3};
    int n = 4;
    
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    
    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool> (totalSum + 1, false));

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    if(arr[0] <= k) dp[0][arr[0]] = true;

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

    int mini = 1e8;
    for(int i = 0; i <= totalSum/2; i++){
        if(dp[n-1][i] == true){
            int s1 = i;
            int s2 = totalSum - i;
            mini = min(mini, abs(s2 - s1));
        }
    }

    cout<<mini<<endl;

    return 0;
}