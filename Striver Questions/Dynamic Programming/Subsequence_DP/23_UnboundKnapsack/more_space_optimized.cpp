#include <bits/stdc++.h>
using namespace std;

int main() {

    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int bag = 10;
    int n = 3;

    vector<int> prev(bag + 1);

    //base Case
    for(int b = wt[0]; b <= bag; b++){
        prev[b] = val[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int b = 0; b <= bag; b++){
            int notPick = prev[b];
            int pick = INT_MIN;
            if(wt[ind] <= b){
                pick = val[ind] + prev[b - wt[ind]];
            }
            prev[b] = max(pick, notPick);
        }
    }

    cout << prev[bag];

    return 0;
}