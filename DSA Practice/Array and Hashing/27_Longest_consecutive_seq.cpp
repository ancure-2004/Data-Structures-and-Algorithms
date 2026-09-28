#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;

        unordered_set<int> seq;
        for(int i = 0; i < n; i++){
            seq.insert(nums[i]);
        }

        int longest = 1;

        for(auto it: seq){
            if(seq.find(it - 1) == seq.end()){
                int x = it;
                int cnt = 1;
                while(seq.find(x + 1) != seq.end()){
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};