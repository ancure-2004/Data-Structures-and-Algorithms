#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int d = 2;

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }

    if(totalSum - d < 0 || (totalSum - d) % 2) return false;

    int k = (totalSum - d) / 2;

    vector<int> prev(k + 1);
    vector<int> curr(k + 1);

    for(int i = 0; i < n; i++){
        prev[0] = 1;
    }

    if(arr[0] <= k) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k; sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(arr[ind] <= sum)
                pick = prev[sum - arr[ind]];

            curr[sum] = pick + notPick;
        }
        prev = curr;
    }

    cout << prev[k];

    return 0;
}