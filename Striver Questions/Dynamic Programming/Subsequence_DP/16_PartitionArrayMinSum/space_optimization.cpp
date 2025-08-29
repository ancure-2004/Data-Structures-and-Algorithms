#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {3, 9, 7, 3};
    int n = 4;
    
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    
    int k = totalSum;

    vector<bool> prev(k + 1, 0);
    vector<bool> curr(k + 1, 0);

    prev[0] = curr[0] = true;

    if(arr[0] <= k) prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){

            bool not_take = prev[target];

            bool take = false;
            if(target >= arr[ind]){
                take = prev[target - arr[ind]];
            }

            curr[target] = (not_take || take);
        }
        prev = curr;
    }

    int mini = 1e8;
    for(int i = 0; i <= totalSum/2; i++){
        if(prev[i] == true){
            int s1 = i;
            int s2 = totalSum - i;
            mini = min(mini, abs(s2 - s1));
        }
    }

    cout<<mini<<endl;

    return 0;
}