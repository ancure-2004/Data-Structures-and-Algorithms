#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        int first = -1;
        int s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(arr[mid] == target){
                first = mid;
                e = mid - 1;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        if(first == -1) return 0;
        
        int last = -1;
        
        s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(arr[mid] == target){
                last = mid;
                s = mid + 1;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return last - first + 1;
    }
};
