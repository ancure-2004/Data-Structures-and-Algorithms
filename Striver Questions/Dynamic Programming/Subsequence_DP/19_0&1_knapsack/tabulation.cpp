#include<bits/stdc++.h>
using namespace std;

int main(){
    int wt[] = {3, 4, 5};
    int val[] = {30, 50, 60};
    int n = 3;
    int bag = 8;

    vector<vector<int>> dp(n, vector<int> (bag + 1, 0));

    for(int i = wt[0]; i <= bag; i++){
        dp[0][i] = val[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int capacity = 0; capacity <= bag; capacity++){
            
            int notTake = 0 + dp[ind - 1][capacity];
            int take = -1e9;
            if(wt[ind] <= capacity){
                take = val[ind] + dp[ind - 1][capacity - wt[ind]];
            }

            dp[ind][capacity] = max(take, notTake);
        }
    }

    cout << dp[n - 1][bag];

    return 0;
}