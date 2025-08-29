#include <bits/stdc++.h>
using namespace std;

int cutting(int ind, int rod, int price[]){
    if(ind == 0){
        return rod * price[0];
    }

    int notPick = cutting(ind - 1, rod, price);
    int pick = INT_MIN;
    if(ind + 1 <= rod){
        pick = price[ind] + cutting(ind, rod - (ind + 1), price);
    }

    return max(pick, notPick);
}

int main() {

    int n = 5;
    int price[] = {2, 5, 7, 8, 10};

    int money = cutting(n - 1, n, price);
    cout << money;

    return 0;
}