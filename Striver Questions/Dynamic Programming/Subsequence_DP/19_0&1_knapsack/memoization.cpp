#include<bits/stdc++.h>
using namespace std;

int maxValue(int ind, int wt[], int val[], int capacity,vector<vector<int>> &dp){

    if(ind == 0){
        if(wt[0] <= capacity) return val[0];
        else return 0;
    }

    if(dp[ind][capacity] != -1){
        return dp[ind][capacity];
    }

    int notTake = 0 + maxValue(ind - 1, wt, val, capacity, dp);
    int take = INT_MIN;
    if(wt[ind] <= capacity){
        take = val[ind] + maxValue(ind - 1, wt, val, capacity - wt[ind], dp);
    }

    return dp[ind][capacity] = max(take, notTake);
}

int main(){
    int wt[] = {3, 4, 5};
    int val[] = {30, 50, 60};
    int n = 3;
    int capacity = 8;

    vector<vector<int>> dp(n, vector<int> (capacity + 1, -1));

    int money = maxValue(n - 1, wt, val, capacity, dp);
    cout << money;

    return 0;
}