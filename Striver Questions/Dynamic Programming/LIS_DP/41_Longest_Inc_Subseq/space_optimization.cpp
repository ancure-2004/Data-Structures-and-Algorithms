#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for(int ind = n - 1; ind >= 0; ind--){
        for(int prevInd = ind - 1; prevInd >= -1; prevInd--){

            int length = prev[prevInd + 1];
            
            if(prevInd == -1 || arr[ind] > arr[prevInd]){
                length = max(length, 1 + prev[ind + 1]);
            }

            curr[prevInd + 1] = length;
        }
        prev = curr;
    }

    cout << prev[-1 + 1];

    return 0;
}