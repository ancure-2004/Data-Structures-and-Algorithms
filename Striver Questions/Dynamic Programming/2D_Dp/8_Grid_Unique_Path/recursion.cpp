#include <bits/stdc++.h>
using namespace std;

int unique_paths(int n, int m){
    if(n == 0 && m == 0){
        return 1;
    }

    if(n < 0 || m < 0)
        return 0;

    //UPWARD
    int UP = unique_paths(n - 1, m);
    //lEFT
    int LEFT = unique_paths(n, m - 1);

    return UP + LEFT;
}

int main() {
    int n = 3;
    int m = 3;
    cout << unique_paths(n - 1, m - 1);

    return 0;
}