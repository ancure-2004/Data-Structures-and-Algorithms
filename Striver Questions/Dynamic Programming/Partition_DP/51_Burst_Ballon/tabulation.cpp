#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> arr = {3, 1, 5, 8};
    int n = 4;

    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            
            if(i > j) continue;

            int maxi = INT_MIN;
            for(int ind = i; ind <= j; ind++){
                int cost = (arr[i - 1] * arr[ind] * arr[j + 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;

        }
    }

    cout << dp[1][n];

    return 0;
}