#include<bits/stdc++.h>
using namespace std;


// My solution that handles the zero edge case 
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int startIndex = 0;
        int endIndex = 0;
        int curr = 0;
        
        int sum = 0;
        int maxi = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                sum = 0;
                continue;
            }
            
            if(sum == 0) curr = i;
            
            sum = sum + arr[i];
            
            
            if(sum > maxi){
                maxi = sum;
                startIndex = curr;
                endIndex = i;
                if(i + 1 < n && arr[i + 1] == 0){
                    endIndex = i + 1;
                }
            }
        }
        
        if(maxi == -1){
            return {-1};
        }
        
        vector<int> result;
        for(int i = startIndex; i <= endIndex; i++){
            result.push_back(arr[i]);
        }
        
        return result;
    }
};


//General Solution
class Solution {
public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();

        int startIndex = 0;
        int endIndex = 0;

        int curr = 0;
        int sum = 0;
        int maxi = -1;
        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            if(arr[i] < 0) {
                sum = 0;
                continue;
            }

            if(sum == 0)
                curr = i;

            sum += arr[i];

            int currLen = i - curr + 1;

            if(sum > maxi || (sum == maxi && currLen > maxLen)) {
                maxi = sum;
                maxLen = currLen;

                startIndex = curr;
                endIndex = i;
            }
        }

        if(maxi == -1)
            return {-1};

        vector<int> result;

        for(int i = startIndex; i <= endIndex; i++) {
            result.push_back(arr[i]);
        }

        return result;
    }
};