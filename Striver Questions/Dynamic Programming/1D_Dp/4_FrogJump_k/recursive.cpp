#include <bits/stdc++.h>
using namespace std;

int k_jumps(int n, int k, int height[]){
    if(n == 0) return 0;
    int min_steps = INT_MAX;
    for(int i = 1; i <= k; i++){
        int jump = INT_MAX;
        if(n - i >= 0)
            jump = abs(height[n] - height[n - i]) + k_jumps(n - i, k, height);
        min_steps = min(min_steps, jump);
    }

    return min_steps;
}

int main() {

    int height[] = { 10, 20, 30 , 40 };
    int n = 4;
    int k = 4;

    cout << k_jumps(n - 1, k, height);

    return 0;
}