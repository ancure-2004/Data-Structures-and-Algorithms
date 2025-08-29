#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1, 3, 4, 5};
    int c = 4;
    int n = 7;

    vector<vector<int>> dp(c + 2, vector<int> (c + 2 , 0));

    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    for(int i = c; i >= 1; i--){
        for(int j = 1; j <= c; j++){
            if(i > j) continue;

            int mini = 1e8;
            for(int ind = i; ind <= j; ind++){
                int cost = (arr[j + 1] - arr[i - 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }

    cout << dp[1][c];

    return 0;
}