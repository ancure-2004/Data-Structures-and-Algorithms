#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        int s = 0, e = n - 1;
        
        if(arr.size() == 1) return 0;
        
        int mini = INT_MAX;
        int index = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(arr[s] <= arr[e]){
                if(arr[s] < mini){
                    mini = arr[s];
                    index = s;
                }
                break;
            }
            
            if(arr[s] <= arr[mid]){
                if(arr[s] < mini){
                    mini = arr[s];
                    index = s;
                }
                s = mid + 1;
            }
            else{
                if(arr[mid] < mini){
                    mini = arr[mid];
                    index = mid;
                }
                e = mid - 1;
            }
        }
        
        return index;
    }
};
