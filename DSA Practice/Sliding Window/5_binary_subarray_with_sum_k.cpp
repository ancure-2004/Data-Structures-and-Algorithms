#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
class Solution {
public:
    int numSubarrayLessThan(vector<int> &nums, int goal) {

        if(goal < 0) return 0;

        int n = nums.size();

        int l = 0;
        int r = 0;

        int sum = 0;
        int cnt = 0;

        while(r < n){
            sum += nums[r];

            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }

            if(sum <= goal){
                cnt += (r - l + 1);
            }

            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int num_subarr_less_than_goal = numSubarrayLessThan(nums, goal);
        int num_subarr_less_than_goal_1 = numSubarrayLessThan(nums, goal - 1);

        return num_subarr_less_than_goal - num_subarr_less_than_goal_1;
    }
};