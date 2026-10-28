#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0, e = n - 1;

        int first = n;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(nums[mid] >= target){
                first = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        if(first == n || nums[first] != target) return {-1, -1};

        int last = n;
        s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(nums[mid] > target){
                last = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return {first, last - 1};
    }
};