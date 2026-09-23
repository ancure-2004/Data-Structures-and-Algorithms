#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int maxOne = 0;
        int current = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                current++;
                maxOne = max(maxOne, current);
            }
            else{
                current = 0;
            }
        }

        return maxOne;
    }
};