#include<bits/stdc++.h>
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

void unique_combos(int ind, int target, int arr[], int n, vector<vector<int>> &ans, vector<int> &desired){
    if(target == 0){
        ans.push_back(desired);
        return ;
    }

    for(int i = ind; i < n; i++){
        if(i > ind && arr[i - 1] == arr[i]) continue;
        if(arr[i] > target) break;

        desired.push_back(arr[i]);
        unique_combos(i + 1, target - arr[i], arr, n, ans, desired);
        desired.pop_back();
    }
}

int main(){

    int arr[] = {1, 1, 1, 2, 2};
    int n = 5;
    int target = 4;

    vector<vector<int>> ans;
    vector<int> desired;

    unique_combos(0, target, arr, n, ans, desired);
    printarr(ans);

    return 0;
}