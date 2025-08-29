#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void subsetSums(int ind, int sum, int arr[], int n, vector<int> &sums){

    if(ind == n){
        sums.push_back(sum);
        return;
    }

    subsetSums(ind + 1, sum + arr[ind], arr, n, sums);
    subsetSums(ind + 1, sum, arr, n, sums);
}

int main(){

    int arr[] = {3, 1, 2};
    int n = 3;

    vector<int> sums;
    subsetSums(0, 0, arr, n, sums);

    sort(sums.begin(), sums.end());
    printarr(sums);

    return 0;
}