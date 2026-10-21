#include<bits/stdc++.h>
using namespace std;

//Most optimal Solution
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0;
        int r = 0;
        int maxi = 0;
        unordered_map<int, int> hash;

        while(r < n){
            hash[fruits[r]]++;

            if(hash.size() > 2){
                hash[fruits[l]]--;
                if(hash[fruits[l]] == 0) hash.erase(fruits[l]);
                l++;
            }

            if(hash.size() <= 2){
                int len = r - l + 1;
                maxi = max(maxi, len);
            }

            r++;
        }

        return maxi;
    }
};