#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    for(int ind = n - 1; ind >= 0; ind--){
        for(int prevInd = ind - 1; prevInd >= -1; prevInd--){

            int length = dp[ind + 1][prevInd + 1];
            
            if(prevInd == -1 || arr[ind] > arr[prevInd]){
                length = max(length, 1 + dp[ind + 1][ind + 1]);
            }

            dp[ind][prevInd + 1] = length;
        }
    }

    cout << dp[0][-1 + 1];

    return 0;
}