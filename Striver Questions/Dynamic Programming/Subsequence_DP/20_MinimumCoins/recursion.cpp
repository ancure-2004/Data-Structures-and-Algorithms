#include <bits/stdc++.h>
using namespace std;

int counting(int ind, int target, int coins[]){
    if(ind == 0)
    if(target % coins[ind] == 0) return target/coins[ind];
    else return 1e9;

    int notTake = 0 + counting(ind - 1, target, coins);
    int take = 1e9;
    if(coins[ind] <= target){
        take = 1 + counting(ind, target - coins[ind], coins);
        
    }
    return min(take, notTake);
}

int main() {

    int coins[] = {1, 2, 3};
    int n = 3;
    int target = 7;

    int no_of_coins = counting(n - 1, target, coins);

    cout << no_of_coins;  

    return 0;
}