#include <bits/stdc++.h>
using namespace std;

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    int profit = 0;
    int mini = prices[0];

    for(int i = 1; i < n; i++){
        profit = max(profit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    
    cout << profit;

    return 0;
}