#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n, 0);

        for(int i = 1; i < n; i++){
            int prevIndex = lps[i - 1];

            while(prevIndex > 0 && s[i] != s[prevIndex]){
                prevIndex = lps[prevIndex - 1];
            }

            lps[i] = prevIndex + (s[i] == s[prevIndex]);
        }

        return s.substr(0, lps.back());
    }
};