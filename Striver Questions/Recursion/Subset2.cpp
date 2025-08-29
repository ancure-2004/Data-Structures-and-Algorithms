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

void unique_sub_combos(int ind, int arr[], int n, vector<int> combo, vector<vector<int>> &unique_combos){

    unique_combos.push_back(combo);

    for(int i = ind; i < n; i++){
        if(i != ind && arr[i] == arr[i - 1]) continue;
        combo.push_back(arr[i]);
        unique_sub_combos(i + 1, arr, n, combo, unique_combos);
        combo.pop_back();
    }
}


int main(){

    int arr[] = {1, 2, 2, 2, 3, 3};
    int n = 5;
    vector<vector<int>> unique_combos;
    vector<int> combo;

    unique_sub_combos(0, arr, n, combo, unique_combos);
    printarr(unique_combos);

    return 0;
}