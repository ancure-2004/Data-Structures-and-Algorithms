#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[r] != 0){
                r++;
                continue;
            }

            if(nums[i] != 0 && nums[r] == 0){
                nums[r] = nums[i];
                nums[i] = 0;
                r++;
            }
        }
    }
};