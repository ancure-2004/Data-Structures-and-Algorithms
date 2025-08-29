#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>> &triangle, int n, int i, int j, vector<vector<int>> &dp){

    if(i == n - 1)
        return triangle[n - 1][j];

    if(dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + min_path_sum(triangle, n, i + 1, j, dp);
    int diagonal = triangle[i][j] + min_path_sum(triangle, n, i + 1, j + 1, dp);

    return dp[i][j] = min(down, diagonal);

}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
        
    vector<vector<int>> dp(4, vector<int>(4, -1));

        int sum = min_path_sum(triangle, 4, 0, 0, dp);

        cout << sum ;

    return 0;
}