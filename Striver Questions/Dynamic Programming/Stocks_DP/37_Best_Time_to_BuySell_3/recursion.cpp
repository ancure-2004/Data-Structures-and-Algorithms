#include <bits/stdc++.h>
using namespace std;

int trading(int ind, int buy, int cap, int prices[], int n){

    if(cap == 0) return 0;
    if(ind == n) return 0;


    if(buy){
        int buyKaro = -prices[ind] + trading(ind + 1, 0, cap, prices, n);
        int skipKaro = trading(ind + 1, 1, cap, prices, n);
        return max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[ind] + trading(ind + 1, 1, cap - 1, prices, n);
        int skipKaro = trading(ind + 1, 0, cap, prices, n);
        return  max(sellKaro, skipKaro);
    }

}

int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = 8;

    int profit = trading(0, 1, 2, prices, n);
    cout << profit;

    return 0;
}