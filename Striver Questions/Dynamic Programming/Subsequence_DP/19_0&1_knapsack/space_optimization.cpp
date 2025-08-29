#include<bits/stdc++.h>
using namespace std;

int main(){
    int wt[] = {3, 4, 5};
    int val[] = {30, 50, 60};
    int n = 3;
    int bag = 8;

    vector<int> prev(bag + 1);
    vector<int> curr(bag + 1);

    for(int i = wt[0]; i <= bag; i++){
        prev[i] = val[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int capacity = 0; capacity <= bag; capacity++){
            
            int notTake = 0 + prev[capacity];
            int take = -1e9;
            if(wt[ind] <= capacity){
                take = val[ind] + prev[capacity - wt[ind]];
            }

           curr[capacity] = max(take, notTake);
        }
        prev = curr;
    }

    cout << prev[bag];

    return 0;
}