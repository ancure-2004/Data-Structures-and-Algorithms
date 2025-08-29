#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 3};
    int n = 3;
    int target = 4;

    vector<int> prev(target + 1);
    vector<int> curr(target + 1);

    for(int  tar = 0; tar <= target; tar++){
        if(tar % arr[0] == 0) prev[tar] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= target; tar++){
            int notPick =  prev[tar]; 
            int pick = 0;
            if(arr[ind] <= tar){
                pick = curr[tar - arr[ind]];
            }

            curr[tar] = pick + notPick;
        }
        prev = curr;
    }

    cout << prev[target];

    return 0;
}