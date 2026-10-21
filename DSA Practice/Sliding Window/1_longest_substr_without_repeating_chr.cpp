#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, bool> appeared;
            for(int j = i; j < s.size(); j++){
                if(appeared[s[j]] == true) break;
                int len = j - i + 1;
                maxLength = max(len, maxLength);
                appeared[s[j]] = true;
            }
        }
        return maxLength;
    }
};


// Optimal Solution 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> hash (255, -1);

        int l = 0;
        int r = 0;
        int maxi = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            int currentLength = r - l + 1;
            maxi = max(maxi, currentLength);

            hash[s[r]] = r;
            r++;
        }

        return maxi;
    }
};