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

void computing_combs(int arr[], int n, int ind, int target, vector<int> &desired_combs, vector<vector<int>> &ans){

    if(ind ==  n){
        if(target == 0){
            ans.push_back(desired_combs);
        }
        return ;
    }

    if(arr[ind] <= target){
        desired_combs.push_back(arr[ind]);
        computing_combs(arr, n, ind, target - arr[ind], desired_combs,ans);
        desired_combs.pop_back();
    }

    computing_combs(arr, n, ind + 1, target, desired_combs, ans);

}

int main(){

    int arr[] = {2, 3, 6, 7};
    int target = 7;
    int n = 4;

    vector<vector<int>> ans;
    vector<int> desired_combs;
    computing_combs(arr, n, 0, target, desired_combs, ans);

    printarr(ans);
    
    return 0;
}