#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
class Solution {
public:
    int subarrayWithLessThanK(vector<int> &nums, int k){
        int n = nums.size();

        int l = 0;
        int r = 0;
        int cnt = 0;
        
        unordered_map<int, int> hash;

        while(r < n){
            hash[nums[r]]++;

            while(hash.size() > k){
                hash[nums[l]]--;
                if(hash[nums[l]] == 0) hash.erase(nums[l]);
                l++;
            }

            cnt += r - l + 1;

            r++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int lessThanK = subarrayWithLessThanK(nums, k);
        int lessThanK_1 = subarrayWithLessThanK(nums, k - 1);

        return lessThanK - lessThanK_1;
    }
};