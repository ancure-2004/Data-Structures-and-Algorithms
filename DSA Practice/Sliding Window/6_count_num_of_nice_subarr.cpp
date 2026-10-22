#include<bits/stdc++.h>
using namespace std;

//Optimal Solution

class Solution {
public:
    int numberOfSubarraysLessThan(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int cnt = 0;
        int oddCnt = 0;

        while(r < n){
            if(nums[r] % 2 != 0) oddCnt++;

            while(oddCnt > k){
                if(nums[l] % 2 != 0) oddCnt--;
                l++;
            }

            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysLessThan(nums, k) - numberOfSubarraysLessThan(nums, k - 1);
    }
};