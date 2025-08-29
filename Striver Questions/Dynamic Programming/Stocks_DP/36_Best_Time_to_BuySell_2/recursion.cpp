#include <bits/stdc++.h>
using namespace std;

int trading(int ind, int buy, int prices[], int n){
    if(ind == n){
        return 0;
    }

    int profit = 0;

    if(buy){
        int buyKaro = -prices[ind] + trading(ind + 1, 0, prices, n);
        int skipKaro = trading(ind + 1, 1, prices, n);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[ind] + trading(ind + 1, 1, prices, n);
        int skipKaro = trading(ind + 1, 0, prices, n);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    int profit = trading(0, 1, prices, n);
    cout << profit;

    return 0;
}