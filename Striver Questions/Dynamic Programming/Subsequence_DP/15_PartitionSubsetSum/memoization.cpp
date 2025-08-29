#include <bits/stdc++.h>
using namespace std;

bool SubsetSumk(int arr[], int ind, int k, vector<vector<bool>> &dp){

    if(k == 0){
        return true;
    }

    if(ind == 0){
        return (arr[ind] == k);
    }

    if(dp[ind][k] != -1){
        return dp[ind][k];
    }

    bool not_take = SubsetSumk(arr, ind - 1, k, dp);

    bool take = false;
    if(k >= arr[ind]){
        take = SubsetSumk(arr, ind - 1, k - arr[ind], dp);
    }

    return dp[ind][k] = (not_take || take);
}

int main() {

    int arr[] = {2, 2, 3, 3, 4, 5};
    int n = 6;

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, -1));

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    if(sum % 2 == 0){
        cout << SubsetSumk(arr, n - 1, sum/2, dp);
    }

    else{
        cout << false;
    }


    return 0;
}