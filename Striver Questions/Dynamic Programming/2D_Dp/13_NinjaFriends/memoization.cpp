#include<bits/stdc++.h>
using namespace std;

int max_chocolates(vector<vector<int>> grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>> &dp){

    //Out of Bound base condition
    if(j1 < 0 || j1 > m - 1 || j2 < 0 || j2 > m - 1){
        return -1e7;
    }

    // Termination Base Condition
    if(i == n - 1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    //Explore all paths
    int maxi = INT_MIN;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + max_chocolates(grid, n, m, i + 1, j1 + dj1, j2 + dj2, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + max_chocolates(grid, n, m, i + 1, j1 + dj1, j2 + dj2, dp));
            }
        }
    }

    return dp[i][j1][j2] = maxi;
}

int main() {

    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int n = 3;
    int m = 4;

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

    cout << max_chocolates(grid, n, m, 0, 0, m - 1, dp);

    return 0;
}