#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int n = 3;
    int m = 4;

    vector<vector<int>> front(m, vector<int>(m));
    vector<vector<int>> curr(m, vector<int>(m));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                front[j1][j2] = grid[n - 1][j1];
            }
            else
            {
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2l; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }

                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m){
                            value += front[j1 + dj1][j2 + dj2];
                            maxi = max(maxi, value);
                        }
                        else{
                            value += -1e8;
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }

    cout << front[0][m-1];

    return 0;
}