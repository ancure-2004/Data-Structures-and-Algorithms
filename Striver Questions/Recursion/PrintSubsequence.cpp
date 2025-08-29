#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    if(arr.size() == 0){
        cout << "{}";
    }
    cout<<endl;
    return;
}

void printSubsequence(int arr[], int n, vector<int> subsequences, int index){
    if(index >= n){
        printarr(subsequences);
        return;
    }
    subsequences.push_back(arr[index]);
    printSubsequence(arr, n, subsequences, index + 1);
    subsequences.pop_back();
    printSubsequence(arr, n, subsequences, index + 1);
}

int main(){
    int arr[] = {3, 1, 2};
    vector<int> subsequences;
    printSubsequence(arr, 3, subsequences, 0);
    return 0;
}