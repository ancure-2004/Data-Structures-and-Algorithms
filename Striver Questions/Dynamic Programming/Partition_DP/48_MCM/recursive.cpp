#include <bits/stdc++.h>
using namespace std;

int MCM(int i, int j, int arr[]){
    if(i == j) return 0;

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM(i, k, arr) + MCM(k + 1, j, arr);
        mini = min(mini, steps);
    }

    return mini;
}

int main(){

    int arr[] = {10, 30, 5, 60};
    int n = 4;

    int product = MCM(1, n-1, arr);
    cout << product;

    return 0;
}