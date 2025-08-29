#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> matrix, int i, int j, int m){

    if(j < 0 || j > m - 1) return 1e7;

    if(i == 0) return matrix[0][j];

    int left = matrix[i][j] + minPathSum(matrix, i - 1, j - 1, m);
    int right = matrix[i][j] + minPathSum(matrix, i - 1, j + 1, m);
    int down = matrix[i][j] + minPathSum(matrix, i - 1, j, m);

    return min(left, min(right, down));
}

int main() {

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int n = 3;
    int m =  3;

    int mini = 1e7;
    for(int i = 0; i < 3; i++){
        int sum = minPathSum(matrix, n - 1, i, m);
        mini = min(sum , mini);
    }

    cout << mini;

    return 0;
}