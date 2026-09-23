#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int current_sum = 0;
        int expected_sum = 0;

        for(int i = 0; i < n; i++){
            current_sum += nums[i];
            expected_sum += i + 1; 
        }

        return expected_sum - current_sum;
    }
};