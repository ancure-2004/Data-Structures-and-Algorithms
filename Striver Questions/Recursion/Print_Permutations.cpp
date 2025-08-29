#include <bits/stdc++.h>
using namespace std;

void printarr(vector<vector<int>> ans){
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void permutations(vector<int> arr, int n, int ind, vector<vector<int>> &all_permutations){
    if(ind == n){
        all_permutations.push_back(arr);
        return ;
    }

    for(int i = ind; i < n; i++){
        swap(arr[ind], arr[i]);
        permutations(arr, n, ind + 1, all_permutations);
        swap(arr[ind], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = 3;

    vector<vector<int>> all_permutations;
    permutations(arr, n, 0, all_permutations);

    printarr(all_permutations);

    return 0;
}