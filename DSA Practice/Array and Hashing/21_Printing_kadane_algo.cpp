#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int sum = 0;

        int ansStart = 0;
        int ansEnd = 0;

        int start = 0;
        for(int i = 0; i < n; i++){

            if(sum == 0) start = i;

            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        vector<int> result;
        for(int i = ansStart; i <= ansEnd; i++){
            result.push_back(nums[i]);
        }

        return result;
    }
};