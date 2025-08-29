#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    int price[] = {2, 5, 7, 8, 10};

    vector<int> prev(n + 1);

    for(int rod = 0; rod <= n; rod++){
        prev[rod] = rod * price[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int rod = 0; rod <= n; rod++){
            int notPick = prev[rod];
            int pick = INT_MIN;
            if(ind + 1 <= rod){
                pick = price[ind] + prev[rod - (ind + 1)];
            }

            prev[rod] = max(pick, notPick);
        }
    }

    cout << prev[n];

    return 0;
}