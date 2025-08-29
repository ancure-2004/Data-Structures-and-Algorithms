#include <bits/stdc++.h>
using namespace std;

int knapSack(int ind, int bag, int wt[], int val[], vector<vector<int>> &dp){
    if(ind == 0){
        return bag/wt[0] * val[0];
    }

    if(dp[ind][bag] != -1){
        return dp[ind][bag];
    }

    int notPick = knapSack(ind - 1, bag, wt, val, dp);
    int pick = INT_MIN;
    if(wt[ind] <= bag){
        pick = val[ind] + knapSack(ind, bag - wt[ind], wt, val, dp);
    }

    return dp[ind][bag] = max(pick, notPick);
}

int main() {

    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int bag = 10;
    int n = 3;

    vector<vector<int>> dp(n, vector<int> (bag + 1, -1));

    int money = knapSack(n - 1, bag, wt, val, dp);
    cout << money;

    return 0;
}