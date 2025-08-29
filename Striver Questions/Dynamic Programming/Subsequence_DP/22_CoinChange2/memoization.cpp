#include <bits/stdc++.h>
using namespace std;

int coinChange(int arr[], int ind, int target, vector<vector<int>> &dp){

    //base case
    if(ind == 0){
        if(target % arr[ind] == 0) return 1;
        else return 0;
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    int notPick =  coinChange(arr, ind - 1, target, dp); 
    int pick = 0;
    if(arr[ind] <= target){
        pick = coinChange(arr, ind, target - arr[ind], dp);
    }

    return dp[ind][target] = pick + notPick;

}

int main() {

    int arr[] = {1, 2, 3};
    int n = 3;
    int target = 4;

    vector<vector<int>> dp(n, vector<int> (target + 1, -1));

    int ways = coinChange(arr, n - 1, target, dp);
    cout << ways;

    return 0;
}