#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = 8;

    vector<int> dp1(n + 1, 1);
    for(int ind = 0; ind < n; ind++){
        for(int prevInd = 0; prevInd < ind; prevInd++){
            if(arr[prevInd] < arr[ind]){
                dp1[ind] = max(dp1[ind], 1 + dp1[prevInd]);
            }
        }
    }

    vector<int> dp2(n + 1, 1);
    for(int ind = n - 1; ind >= 0; ind--){
        for(int prevInd = n - 1; prevInd > ind; prevInd--){
            if(arr[prevInd] < arr[ind]){
                dp2[ind] = max(dp2[ind], 1 + dp2[prevInd]);
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    cout << maxi;

    return 0;
}