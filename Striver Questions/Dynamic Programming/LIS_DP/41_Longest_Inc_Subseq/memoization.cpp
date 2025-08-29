#include <bits/stdc++.h>
using namespace std;

int LIS(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp){

    if(ind == n)
        return 0;

    if(dp[ind][prevInd + 1] != -1){
        return dp[ind][prevInd + 1];
    }

    int length = LIS(ind + 1, prevInd, n, arr, dp);
    
    if(prevInd == -1 || arr[ind] > arr[prevInd]){
        length = max(length, 1 + LIS(ind + 1, ind, n, arr, dp));
    }

    return dp[ind][prevInd + 1] = length;
}

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    vector<vector<int>> dp(n, vector<int> (n + 1, -1));

    int length = LIS(0, -1, n, arr, dp);
    cout << length;

    return 0;
}