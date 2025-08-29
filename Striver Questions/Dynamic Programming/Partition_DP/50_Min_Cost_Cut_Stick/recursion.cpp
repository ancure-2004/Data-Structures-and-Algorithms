#include <bits/stdc++.h>
using namespace std;

int cutting(int i, int j, vector<int> arr){
    if(i > j) return 0;

    int mini = 1e8;
    for(int ind = i; ind <= j; ind++){
        int cost = (arr[j + 1] - arr[i - 1]) + cutting(i, ind - 1, arr) + cutting(ind + 1, j, arr);
        mini = min(cost, mini);
    }

    return mini;
}

int main() {

    vector<int> arr = {1, 3, 4, 5};
    int n = 7;

    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    int cost = cutting(1, arr.size() - 2, arr);
    cout << cost;

    return 0;
}