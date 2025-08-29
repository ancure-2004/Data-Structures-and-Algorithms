#include <bits/stdc++.h>
using namespace std;

//Recursive
int jumps(int n, int height[]){

    if(n == 0) return 0;
    
    int left = abs(height[n] - height[n - 1]) + jumps(n - 1, height);

    int right = INT_MAX;
    if(n > 1)
        right = abs(height[n] - height[n - 2]) + jumps(n - 2, height);

    return min(left, right);
}

int main(){

    int n = 4;
    vector<int> dp(n + 1, -1);

    int height[] = {10, 20, 30, 10};
    cout << jumps(n - 1, height)<<endl;

    return 0;
}