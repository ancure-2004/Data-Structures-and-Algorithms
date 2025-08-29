#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 3, 5, 4, 7};
    int n = 5;

    vector<int> dp(n, 1), cnt(n, 1);

    int maxi = 1;
    for(int ind = 0; ind < n; ind++){
        for(int prevInd = 0; prevInd < ind; prevInd++){
            if(arr[prevInd] < arr[ind] && 1 + dp[prevInd] > dp[ind]){
                dp[ind] = 1 + dp[prevInd];
                cnt[ind] = cnt[prevInd];
            }
            else if(arr[prevInd] < arr[ind] && 1 + dp[prevInd] == dp[ind]){
                cnt[ind] += cnt[prevInd];
            }
        }
        maxi = max(dp[ind], maxi);
    }

    int nos = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi) nos += cnt[i];
    }

    cout << nos;

    return 0;
}