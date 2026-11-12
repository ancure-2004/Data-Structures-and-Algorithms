#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisor(vector<int> nums, int threshold, int mid){
        int divi = 0;

        for(int i = 0; i < nums.size(); i++){
            divi += ceil((double) nums[i]/mid);
        }

        if(divi <= threshold){
            return true;
        }

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
        }

        int low = 1;
        int high = maxi;

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(divisor(nums, threshold, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};