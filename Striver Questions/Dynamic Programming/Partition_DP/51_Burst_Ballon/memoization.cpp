#include<bits/stdc++.h>
using namespace std;

int burst(int i, int j, vector<int> arr, vector<vector<int>> &dp){

    if(i > j) return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int cost = (arr[i - 1] * arr[ind] * arr[j + 1]) + burst(i, ind - 1, arr, dp) + burst(ind + 1, j, arr, dp);
        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

int main() {
    
    vector<int> arr = {3, 1, 5, 8};
    int n = 4;

    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

    int cost = burst(1, n, arr, dp);
    cout << cost;

    return 0;
}