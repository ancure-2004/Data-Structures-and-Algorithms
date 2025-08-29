#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
        
    vector<vector<int>> dp(n, vector<int>(n, 0));

    //Base Case
    for(int j = 0; j < n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){

            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    cout << dp[0][0] ;

    return 0;
}