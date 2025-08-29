#include <bits/stdc++.h>
using namespace std;

int non_adjacent_sum(int n, int arr[]){

    if(n == 0) return arr[n];
    if(n < 0) return 0;

    int pick = arr[n] + non_adjacent_sum(n - 2, arr);
    int notPick = 0 + non_adjacent_sum(n - 1, arr);

    return max(pick, notPick);
}

int main() {

    int arr[] = {2, 1, 4, 9};
    int n = 4;

    cout << non_adjacent_sum(n - 1, arr);

    return 0;
}