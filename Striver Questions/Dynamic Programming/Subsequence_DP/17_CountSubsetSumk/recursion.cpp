#include <bits/stdc++.h>
using namespace std;

int countSubset(int ind, int k, int arr[]){
    if(k == 0)
        return 1;

    if(ind == 0)
        return (arr[ind] == k);

    int notPick = countSubset(ind - 1, k, arr);
    int pick = 0;
    if(arr[ind] <= k)
        pick = countSubset(ind - 1, k - arr[ind], arr);

    return pick + notPick;
}

int main() {

    int arr[] = {2, 3, 5, 16, 8, 10};
    int n = 6;
    int k = 10;

    int count = countSubset(n - 1, k, arr);

    cout << count;

}