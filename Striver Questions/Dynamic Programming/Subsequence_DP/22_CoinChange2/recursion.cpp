#include <bits/stdc++.h>
using namespace std;

int coinChange(int arr[], int ind, int target){

    //base case
    if(ind == 0){
        if(target % arr[ind] == 0) return 1;
        else return 0;
    }

    int notPick =  coinChange(arr, ind - 1, target); 
    int pick = 0;
    if(arr[ind] <= target){
        pick = coinChange(arr, ind, target - arr[ind]);
    }

    return pick + notPick;

}

int main() {

    int arr[] = {1, 2, 3};
    int n = 3;
    int target = 4;

    int ways = coinChange(arr, n - 1, target);
    cout << ways;

    return 0;
}