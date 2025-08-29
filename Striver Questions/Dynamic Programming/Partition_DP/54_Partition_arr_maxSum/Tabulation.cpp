#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = 7;

    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int len = 0;

        for(int j = i; j < min(i + k, n); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (maxi * len) + dp[j + 1];
            ans = max(ans, sum);
        }
        dp[i] = ans;
    }

    cout << dp[0];

    return 0;
}