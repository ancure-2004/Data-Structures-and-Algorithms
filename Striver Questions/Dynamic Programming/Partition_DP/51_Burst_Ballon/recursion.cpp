#include<bits/stdc++.h>
using namespace std;

int burst(int i, int j, vector<int> arr){

    if(i > j) return 0;

    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int cost = (arr[i - 1] * arr[ind] * arr[j + 1]) + burst(i, ind - 1, arr) + burst(ind + 1, j, arr);
        maxi = max(maxi, cost);
    }

    return maxi;
}

int main() {
    
    vector<int> arr = {3, 1, 5, 8};
    int n = 4;

    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    int cost = burst(1, n, arr);
    cout << cost;

    return 0;
}