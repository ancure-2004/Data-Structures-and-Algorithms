#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> result;
        int previous_leader = n - 1;
        result.push_back(arr[previous_leader]);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] >= arr[previous_leader]){
                previous_leader = i;
                result.push_back(arr[i]);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};