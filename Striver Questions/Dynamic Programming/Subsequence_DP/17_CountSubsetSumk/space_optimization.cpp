#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {2, 3, 5, 16, 8, 10};
    int n = 6;
    int k = 10;

    vector<int> prev(k + 1);
    vector<int> curr(k + 1);

    prev[0] = curr[0] = 1;

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