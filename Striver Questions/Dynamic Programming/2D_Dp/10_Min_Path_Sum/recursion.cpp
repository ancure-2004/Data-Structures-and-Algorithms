#include <bits/stdc++.h>
using namespace std;

int minPathSum(int n, int m, int arr[][3]){

    if(n == 0 && m == 0) return arr[n][m];
    
    if(n < 0 || m  < 0) return 1e9;
    
    //Our starting point was bottom corner so instead of down and right we will use opposite
    int UP = arr[n][m] + minPathSum(n - 1, m, arr);
    int LEFT = arr[n][m] + minPathSum(n, m - 1, arr);

    return min(UP, LEFT);
}

int main() {

    int arr[2][3] = {{5, 9 , 6}, {11, 5, 2}};

    int sum = minPathSum(1, 2, arr);

    cout << sum << endl;

    return 0;
}