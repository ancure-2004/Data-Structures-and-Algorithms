#include <bits/stdc++.h>
using namespace std;

// Brute Force 
class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> result;
        
        for(int i = 1; i <= n; i++){
            int number = 0;
            for(int j = 0; j < n; j++){
                if(arr[j] == i){
                    number++;
                }
            }
            result.push_back(number);
        }
        
        return result;
    }
};


//Optimized
class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> hash(n + 1);
        for(int i = 0; i < n; i++){
            hash[arr[i]]++;
        }
        
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            result[i] = hash[i + 1];
        }
        
        return result;
    }
};
