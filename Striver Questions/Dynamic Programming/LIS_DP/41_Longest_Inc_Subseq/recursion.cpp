#include <bits/stdc++.h>
using namespace std;

int LIS(int ind, int prevInd, int n, int arr[]){

    if(ind == n)
        return 0;

    int length = LIS(ind + 1, prevInd, n, arr);

    if(prevInd == -1 || arr[ind] > arr[prevInd]){
        length = max(length, 1 + LIS(ind + 1, ind, n, arr));
    }

    return length;
}

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    int length = LIS(0, -1, n, arr);
    cout << length;

    return 0;
}