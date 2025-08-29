#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int k = 6;

    vector<bool> prev(k + 1, 0);
    vector<bool> curr(k + 1, 0);

    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){

            bool not_take = prev[target];

            bool take = false;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }

            curr[target] = (not_take || take);
        }
        prev = curr;
    }

    cout << prev[k];

    return 0;
}