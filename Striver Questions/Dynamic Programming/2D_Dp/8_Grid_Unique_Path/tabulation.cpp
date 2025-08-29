#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) continue;
            
            int UP = 0, LEFT = 0;
            if(i - 1 >= 0) UP = dp[i - 1][j];
            if(j - 1 >= 0) LEFT = dp[i][j - 1]; 

            dp[i][j] = UP + LEFT;
        }
    }
    cout << dp[n-1][m-1];

    return 0;
}