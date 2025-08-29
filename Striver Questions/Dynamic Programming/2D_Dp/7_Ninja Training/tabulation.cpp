#include <bits/stdc++.h>
using namespace std;

int main()
{
    int points[4][3] = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int days = 4;
    int task = 3;

    vector<vector<int>> dp(days, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < days; day++)
    {
        for (int last_ind = 0; last_ind <= 3; last_ind++)
        {
            int maxi = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i != last_ind)
                {
                    int curr_points = points[day][i] + dp[day - 1][i];
                    maxi = max(curr_points, maxi);
                }
            }
            dp[day][last_ind] = maxi;
        }
    }

    cout << dp[days - 1][3];

    return 0;
}