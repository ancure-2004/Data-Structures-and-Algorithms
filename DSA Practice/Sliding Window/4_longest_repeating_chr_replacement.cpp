#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int map[26] = {0};
        int maxi = 0;

        while(r < n){
            map[s[r] - 'A']++;
            maxFreq = max(maxFreq, map[s[r] - 'A']);

            while((r - l + 1) - maxFreq > k){
                map[s[l] - 'A']--;
                maxFreq = 0;
                for(int i = 0; i <= 25; i++) maxFreq = max(maxFreq, map[i]);
                l++;
            }

            if((r - l + 1) - maxFreq <= k){
                maxi = max(maxi, r - l + 1);
            }

            r++;
        }

        return maxi;
    }
};


//Most Optimal Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int map[26] = {0};
        int maxi = 0;

        while(r < n){
            map[s[r] - 'A']++;
            maxFreq = max(maxFreq, map[s[r] - 'A']);

            if((r - l + 1) - maxFreq > k){
                map[s[l] - 'A']--;
                l++;
            }

            if((r - l + 1) - maxFreq <= k){
                maxi = max(maxi, r - l + 1);
            }

            r++;
        }

        return maxi;
    }
};