#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expand(string str, int left, int right){
        while(left >= 0 && right < str.size() && str[left] == str[right]){
            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            int lenOdd = expand(s, i, i);
            int lenEven = expand(s, i, i + 1);

            int maxLen = max(lenOdd, lenEven);

            if(maxLen > end - start){
                start = i - (maxLen - 1)/2;
                end = i + maxLen/2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};