#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int n = 3;
    int m =  3;

    vector<int> prev (m);

    for(int j = 0; j < m; j++){
        prev[j] = matrix[0][j];
    }

    for(int i = 1; i < n; i++){
        vector<int> curr(m);
        for(int j = 0; j < m; j++){

            int left = INT_MAX, right = INT_MAX;
            if(j - 1 >= 0) left = matrix[i][j] + prev[j - 1];

            if(j + 1 < m) right = matrix[i][j] + prev[j + 1];

            int down = matrix[i][j] + prev[j];

            curr[j] = min(left, min(right, down));
        }
        prev = curr;
    }

    int mini = 1e7;
    for(int i = 0; i < m; i++){
        int sum = prev[i];
        mini = min(sum , mini);
    }
 
    cout << mini;

    return 0;
}