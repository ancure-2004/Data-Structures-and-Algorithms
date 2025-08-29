#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {1, 3, 2, 8, 4, 9};
    int n = 6;
    int fees = 2;

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
                //Just subtracting the fees rest same
                int sellKaro = (prices[ind] - fees) + next[1];
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