#include <bits/stdc++.h>
using namespace std;

int max_points(int days, int last, int points[][3], vector<vector<int>> &dp){
    if(days == 0){
        int maxi = INT_MIN;
        for(int i = 0; i <= 2; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[days][last] != -1){
        return dp[days][last];
    }

    int maxi = INT_MIN;
    for(int i = 0; i <= 2; i++){
        if(i != last){
            int curr_points = points[days][i] + max_points(days - 1, i, points, dp);
            maxi = max(curr_points, maxi);
        }
    }

    return dp[days][last] = maxi;
}

int main(){
    int points[4][3] = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int days = 4;
    int task = 3;

    vector<vector<int>> dp(days, vector<int> (4, -1));
    cout << max_points(days - 1, 3, points, dp);

    return 0;
}