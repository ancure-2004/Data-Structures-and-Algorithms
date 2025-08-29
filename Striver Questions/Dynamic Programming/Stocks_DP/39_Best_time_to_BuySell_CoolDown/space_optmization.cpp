#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {4, 9, 0, 4, 10};
    int n = 5;

    vector<int> next2(2, 0);
    vector<int> next1(2, 0);
    vector<int> curr(2, 0);

    for(int ind = n - 1; ind >= 0; ind--){

        int buyKaro = -prices[ind] + next1[0];
        int skipKaro1 = next1[1];
        curr[1] = max(buyKaro, skipKaro1);

        int sellKaro = prices[ind] + next2[1];
        int skipKaro2 = next1[0];
        curr[0] = max(sellKaro, skipKaro2);

        next2 = next1;
        next1 = curr;
    }

    cout << next1[1];

    return 0;
}