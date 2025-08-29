#include <bits/stdc++.h>
using namespace std;

int main()
{
    int points[4][3] = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int days = 4;
    int task = 3;

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < days; day++)
    {
        vector<int> temp(4, 0);
        for (int last_ind = 0; last_ind <= 3; last_ind++)
        {
            int maxi = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i != last_ind)
                {
                    int curr_points = points[day][i] + prev[i];
                    maxi = max(curr_points, maxi);
                }
            }
            temp[last_ind] = maxi;
        }
        prev = temp;
    }

    cout << prev[3];

    return 0;
}