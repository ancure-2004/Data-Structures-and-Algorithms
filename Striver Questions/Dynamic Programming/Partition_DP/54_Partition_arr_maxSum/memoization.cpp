#include <bits/stdc++.h>
using namespace std;

int partition(int i, int k, int n, int arr[], vector<int> &dp){
    if(i == n) return 0;
 
    if(dp[i] != -1){
        return dp[i];
    }

    int maxi = INT_MIN;
    int ans = INT_MIN;
    int len = 0;

    for(int j = i; j < min(i + k, n); j++){
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (maxi * len) + partition(j + 1, k, n, arr, dp);
        ans = max(ans, sum);
    }

    return dp[i] = ans;
}

int main() {

    int arr[] = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = 7;

    vector<int> dp(n, -1);

    int sum = partition(0, k, n, arr, dp);
    cout << sum;

    return 0;
}