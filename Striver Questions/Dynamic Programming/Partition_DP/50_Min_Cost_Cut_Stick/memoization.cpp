#include <bits/stdc++.h>
using namespace std;

int cutting(int i, int j, vector<int> arr, vector<vector<int>> &dp){
    if(i > j) return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e8;
    for(int ind = i; ind <= j; ind++){
        int cost = (arr[j + 1] - arr[i - 1]) + cutting(i, ind - 1, arr, dp) + cutting(ind + 1, j, arr, dp);
        mini = min(cost, mini);
    }

    return dp[i][j] = mini;
}

int main() {

    vector<int> arr = {1, 3, 4, 5};
    int n = 7;

    vector<vector<int>> dp(arr.size() + 1, vector<int> (arr.size() + 1, -1));

    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    int cost = cutting(1, arr.size() - 2, arr, dp);
    cout << cost;

    return 0;
}