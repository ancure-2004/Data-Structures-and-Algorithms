#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {

        vector<int> lps(s.size(), 0);
        for(int i = 1; i < lps.size(); i++){
            int prevIndx = lps[i - 1];
            while(prevIndx > 0 && s[prevIndx] != s[i]){
                prevIndx = lps[prevIndx - 1];
            }
            lps[i] = prevIndx + (s[i] == s[prevIndx]);
        }

        return s.substr(0, lps.back());
    }
};