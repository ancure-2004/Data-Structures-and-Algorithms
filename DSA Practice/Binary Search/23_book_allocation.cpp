#include<bits/stdc++.h>
using namespace std;

int isAllocated(vector<int> arr, int mid, int m){
    int students = 1;
    int pagesStu = 0;

    for(int i = 0; i < arr.size(); i++){
        if(pagesStu + arr[i] <= mid){
            pagesStu += arr[i];
        }
        else{
            pagesStu = arr[i];
            students++;
        }
    }

    if(students <= m) return true;

    return false;

}

int findPages(vector<int>& arr, int n, int m) {
    
    if(m > n) return -1;


    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }

    int low = maxi;
    int high = sum;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(isAllocated(arr, mid, m)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;

}