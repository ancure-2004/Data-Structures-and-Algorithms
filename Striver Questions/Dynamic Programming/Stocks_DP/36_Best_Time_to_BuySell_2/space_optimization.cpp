#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){

            int profit = 0;
            if(buy){
                int buyKaro = -prices[ind] + next[0];
                int skipKaro = next[1];
                profit = max(buyKaro, skipKaro);
            }
            else{
                int sellKaro = prices[ind] + next[1];
                int skipKaro = next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    cout << next[1];

    return 0;
}