#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
        
    vector<int> front(n);

    //Base Case
    for(int j = 0; j < n; j++){
        front[j] = triangle[n-1][j];
    }

    for(int i = n - 2; i >= 0; i--){
        vector<int> curr(n);
        for(int j = i; j >= 0; j--){

            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }

    cout << front[0] ;

    return 0;
}