#include <bits/stdc++.h>
using namespace std;

int main() {

    int coins[] = {1, 2, 3};
    int n = 3;
    int target = 7;

    vector<int> prev(target + 1);
    vector<int> curr(target + 1);

    for(int i = 0; i <= target; i++){
        if(i % coins[0] == 0) prev[i] = i/coins[0];
        else prev[i] = 1e9;
    }

    for(int ind = 1; ind < n; ind++){
        for(int t = 0; t <= target; t++){
            int notTake = 0 + prev[t];
            int take = 1e9;
            if(coins[ind] <= t){
                take = 1 + curr[t - coins[ind]];
                
            }
            curr[t] = min(take, notTake);
        }
        prev = curr;
    }  

    cout << prev[target];

    return 0;
}