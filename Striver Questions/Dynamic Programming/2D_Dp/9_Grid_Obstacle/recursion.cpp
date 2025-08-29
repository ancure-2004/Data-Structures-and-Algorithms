#include <bits/stdc++.h>
using namespace std;

int unique_paths(int n, int m, int arr[][3]){
    if(n >= 0 && m >= 0 && arr[n][m] == -1){
        return 0;
    }
    if(n == 0 && m == 0){
        return 1;
    }
    if(n < 0 || m < 0)
        return 0;

    //UPWARD
    int UP = unique_paths(n - 1, m, arr);
    //lEFT
    int LEFT = unique_paths(n, m - 1, arr);

    return UP + LEFT;
}

int main() {
    int n = 3;
    int m = 3;

    int arr[3][3] = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout << unique_paths(n - 1, m - 1, arr);

    return 0;
}