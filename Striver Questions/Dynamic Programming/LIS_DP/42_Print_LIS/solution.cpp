#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {5, 4, 11, 1, 16, 8};
    int n = 6;

    vector<int> dp(n, 1);
    vector<int> hash(n);

    int lastIndex = 0;

    int maxi = 0;
    for(int ind = 0; ind < n; ind++){
        hash[ind] = ind;
        for(int prevInd = 0; prevInd < ind; prevInd++){
            if(arr[prevInd] < arr[ind] &&  1 + dp[prevInd] > dp[ind]){
                dp[ind] = 1 + dp[prevInd];
                hash[ind] = prevInd;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            lastIndex = ind;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }cout <<endl;

    return 0;
}