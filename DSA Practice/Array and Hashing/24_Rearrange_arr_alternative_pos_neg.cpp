#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        int free_odd = 0;
        int free_even = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                result[free_odd] = nums[i];
                if(free_odd + 2 < n){
                    free_odd += 2;
                }
            }

            else{
                result[free_even] = nums[i];
                if(free_even + 2 < n){
                    free_even += 2;
                }
            }
        }

        return result;
    }
};