#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ')' && cnt1 > 0) cnt1--;
            else if(s[i] == '(') cnt1++;
            else cnt2++;
        }

        return cnt1 + cnt2;
    }
};