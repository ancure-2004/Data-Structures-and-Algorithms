#include<bits/stdc++.h>
using namespace std;

bool isSubsetK(int arr[], int ind, int k, vector<vector<int>> &dp){

    if(k == 0){
        return true;
    }

    if(ind == 0){
        return (arr[ind] == k);
    }

    if(dp[ind][k] != -1){
        return dp[ind][k];
    }

    bool not_take = isSubsetK(arr, ind - 1, k, dp);

    bool take = false;
    if(k >= arr[ind]){
        take = isSubsetK(arr, ind - 1, k - arr[ind], dp);
    }

    return dp[ind][k] = (not_take || take);
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int k = 6;

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

    if(isSubsetK(arr, n - 1, k, dp)){
        cout << "true";
    }

    else cout << "false";

    return 0;
}