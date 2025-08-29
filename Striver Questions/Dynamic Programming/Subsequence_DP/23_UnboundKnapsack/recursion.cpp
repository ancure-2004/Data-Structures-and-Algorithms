#include <bits/stdc++.h>
using namespace std;

int knapSack(int ind, int bag, int wt[], int val[]){
    if(ind == 0){
        return bag/wt[0] * val[0];
    }

    int notPick = knapSack(ind - 1, bag, wt, val);
    int pick = INT_MIN;
    if(wt[ind] <= bag){
        pick = val[ind] + knapSack(ind, bag - wt[ind], wt, val);
    }

    return max(pick, notPick);
}

int main() {

    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int bag = 10;
    int n = 3;

    int money = knapSack(n - 1, bag, wt, val);
    cout << money;

    return 0;
}