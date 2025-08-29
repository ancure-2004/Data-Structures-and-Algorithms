#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = 8;

    vector<vector<int>> next(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));

    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){

                if(buy){
                    int buyKaro = -prices[ind] + next[0][cap];
                    int skipKaro = next[1][cap];
                    curr[buy][cap] = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[ind] + next[1][cap - 1];
                    int skipKaro = next[0][cap];
                    curr[buy][cap] = max(sellKaro, skipKaro);
                }
            }
        }
        next = curr;
    }

    cout << next[1][2];

    return 0;
}