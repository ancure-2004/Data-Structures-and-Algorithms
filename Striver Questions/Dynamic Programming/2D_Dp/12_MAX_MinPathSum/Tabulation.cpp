#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int n = 3;
    int m =  3;

    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int j = 0; j < m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){

            int left = INT_MAX, right = INT_MAX;
            if(j - 1 >= 0) left = matrix[i][j] + dp[i - 1][j - 1];

            if(j + 1 < m) right = matrix[i][j] + dp[i - 1][j + 1];

            int down = matrix[i][j] + dp[i - 1][j];

            dp[i][j] = min(left, min(right, down));
        }
    }

    int mini = 1e7;
    for(int i = 0; i < m; i++){
        int sum = dp[n - 1][i];
        mini = min(sum , mini);
    }
 
    cout << mini;

    return 0;
}