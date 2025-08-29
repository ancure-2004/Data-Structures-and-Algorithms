#include <bits/stdc++.h>
using namespace std;

int partition(int i, int k, int n, int arr[]){
    if(i == n) return 0;

    int maxi = INT_MIN;
    int ans = INT_MIN;
    int len = 0;

    for(int j = i; j < min(i + k, n); j++){
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (maxi * len) + partition(j + 1, k, n, arr);
        ans = max(ans, sum);
    }

    return ans;
}

int main() {

    int arr[] = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = 7;

    int sum = partition(0, k, n, arr);
    cout << sum;

    return 0;
}