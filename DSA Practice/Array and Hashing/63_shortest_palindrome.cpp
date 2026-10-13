#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        string srev = s;
        reverse(srev.begin(), srev.end());

        string temp = s + '#' + srev;
        vector<int> lps(temp.size(), 0);

        for(int i = 1; i < temp.size(); i++){
            int prevIndex = lps[i - 1];

            while(prevIndex > 0 && temp[i] != temp[prevIndex]){
                prevIndex = lps[prevIndex - 1];
            }

            lps[i] = prevIndex + (temp[i] == temp[prevIndex]);
        }

        return srev.substr(0, n - lps.back()) + s;
    }
};