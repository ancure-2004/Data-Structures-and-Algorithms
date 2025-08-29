#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {2, 2, 3, 3, 4, 5};
    int n = 6;

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    bool ans = false;

    vector<bool> prev(sum/2 + 1, 0);
    vector<bool> curr(sum/2 + 1, 0);

    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= sum/2; target++){

            bool not_take = prev[target];

            bool take = false;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }

            curr[target] = (not_take || take);
        }
        prev = curr;
    }

    if(sum % 2 == 0){
        ans = prev[sum/2];
    }
    else{
        cout << false;
    }

    return 0;
}