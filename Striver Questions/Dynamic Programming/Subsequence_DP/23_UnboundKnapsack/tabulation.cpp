#include <bits/stdc++.h>
using namespace std;

int main() {

    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int bag = 10;
    int n = 3;

    vector<vector<int>> dp(n, vector<int> (bag + 1, 0));

    //base Case
    for(int b = 0; b <= bag; b++){
        dp[0][b] = ((int)(b/wt[0])) * val[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int b = 0; b <= bag; b++){
            int notPick = dp[ind - 1][b];
            int pick = INT_MIN;
            if(wt[ind] <= b){
                pick = val[ind] + dp[ind][b - wt[ind]];
            }
            dp[ind][b] = max(pick, notPick);
        }
    }

    cout << dp[n-1][bag];

    return 0;
}