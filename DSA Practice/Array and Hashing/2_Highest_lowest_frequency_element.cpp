#include <bits/stdc++.h>
using namespace std;

//Sliding window approach
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        int r = 0;
        int l = 0;

        int maxFreq = 1;
        long long sum = 0;

        while(r < n){
            sum = sum + nums[r];

            while((long long)(r - l + 1) * nums[r] - sum > k){
                sum = sum - nums[l];
                l++;
            }
        
            maxFreq = max(maxFreq, r - l + 1);
            
            r++;
        }

        return maxFreq;
    }
};