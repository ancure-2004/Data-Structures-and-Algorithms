#include<bits/stdc++.h>
using namespace std;

bool isSubsetK(int arr[], int ind, int k){

    if(k == 0){
        return true;
    }

    if(ind == 0){
        return (arr[ind] == k);
    }

    bool not_take = isSubsetK(arr, ind - 1, k);

    bool take = false;
    if(k >= arr[ind]){
        take = isSubsetK(arr, ind - 1, k - arr[ind]);
    }

    return not_take || take;
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int k = 4;

    if(isSubsetK(arr, n - 1, k)){
        cout << "true";
    }

    else cout << "false";

    return 0;
}