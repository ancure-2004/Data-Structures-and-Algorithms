#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expand(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int end = 0;

        for(int centre = 0; centre < n; centre++){
            int lenOdd = expand(s, centre, centre);
            int lenEven = expand(s, centre, centre + 1);

            int maxLen = max(lenOdd, lenEven);
            
            if(maxLen > end - start){
                start = centre - (maxLen - 1)/2;
                end = centre + (maxLen)/2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};