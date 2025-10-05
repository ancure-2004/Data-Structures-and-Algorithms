#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> image, int iniColor, int color){

        ans[row][col] = color;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
            {
                dfs(nrow, ncol, ans, image, iniColor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, iniColor, color);

        return ans;
    }
};