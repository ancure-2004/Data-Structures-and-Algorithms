#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        string srev = s;
        reverse(srev.begin(), srev.end());
        string temp = s + '#' + srev;
        vector<int> lps(temp.size(), 0);

        for(int i = 1; i < lps.size(); i++){
            int prevIndx = lps[i - 1];
            while(prevIndx > 0 && temp[prevIndx] != temp[i]){
                prevIndx = lps[prevIndx - 1];
            }
            lps[i] = prevIndx + (temp[i] == temp[prevIndx]);
        }

        return srev.substr(0, n - lps.back()) + s;
    }
};