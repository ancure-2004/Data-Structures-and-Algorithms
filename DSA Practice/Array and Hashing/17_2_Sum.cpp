#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> answer(2, 0);
        for(int i = 0; i < n; i++){
            int rem = target - nums[i];
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                }
                if(nums[j] == rem){
                    answer[0] = i;
                    answer[1] = j;
                }
            }
        }

        return answer;
    }
};

//OPTIMAL SOLUTION - Hash Map [O(n), O(n)]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> hash;

        vector<int> result(2, 0);
        for(int i = 0; i < n; i++){
            int rem = target - nums[i];
            if(hash.find(rem) != hash.end()){
                result[0] = i;
                result[1] = hash[rem];
                break;
            }
            hash[nums[i]] = i;
        }

        return result;
    }
};


//Optimal Approach - TWO POINTERS [O(nlogn + n), O(1)] -- If indices doesnt matter sorting will mess up the indices
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = n - 1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == target){
                return {l, r};
            }

            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }

        return {0, 0};
    }
};