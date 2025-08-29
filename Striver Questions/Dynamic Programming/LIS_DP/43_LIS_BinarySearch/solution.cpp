#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 7, 8, 4, 5, 6, -1, 9};
    int n = 8;

    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    cout << temp.size();

    return 0;
}