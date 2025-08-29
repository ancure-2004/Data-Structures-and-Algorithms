#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {5, 4, 11, 1, 16, 8};
    int n = 8;

    vector<int> dp(n + 1, 1);

    int maxi = 0;
    for(int ind = 0; ind < n; ind++){
        for(int prevInd = 0; prevInd < ind; prevInd++){
            if(arr[prevInd] < arr[ind]){
                dp[ind] = max(dp[ind], 1 + dp[prevInd]);
            }
        }
        maxi = max(dp[ind], maxi);
    }

    cout << maxi;

    return 0;
}