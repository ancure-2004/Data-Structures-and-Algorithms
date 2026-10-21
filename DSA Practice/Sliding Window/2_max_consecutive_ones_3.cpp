#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 0;
        for(int i = 0; i < n; i++){
            int zeros = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zeros++;
                
                if(zeros <= k){
                    int len = j - i + 1;
                    maxi = max(maxi, len);
                }
                else{
                    break;
                }
            }
        }

        return maxi;
    }
};

//Optimal Solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 0;
        int zeroes = 0;
        int l = 0;
        int r = 0;

        while(r < n){
            if(nums[r] == 0) zeroes++;

            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }

            if(zeroes <= k){
                int len = r - l + 1;
                maxi = max(maxi, len);
            }

            r++;
        }

        return maxi;
    }
};


//Most Optimal Solution - the inside while loop just replace while with if, with this we can maintain the longest window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 0;
        int zeroes = 0;
        int l = 0;
        int r = 0;

        while(r < n){
            if(nums[r] == 0) zeroes++;

            if(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }

            if(zeroes <= k){
                int len = r - l + 1;
                maxi = max(maxi, len);
            }

            r++;
        }

        return maxi;
    }
};