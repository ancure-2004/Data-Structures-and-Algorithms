#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>> &triangle, int n, int i, int j){

    if(i == n - 1)
        return triangle[n - 1][j];

    int down = triangle[i][j] + min_path_sum(triangle, n, i + 1, j);
    int diagonal = triangle[i][j] + min_path_sum(triangle, n, i + 1, j + 1);

    return min(down, diagonal);

}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};


        int sum = min_path_sum(triangle, 4, 0, 0);

        cout << sum ;

    return 0;
}