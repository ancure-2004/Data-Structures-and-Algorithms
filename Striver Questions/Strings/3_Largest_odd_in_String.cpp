#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--){
            int odd = num[i] - '0';
            if((odd & 1) == 1){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};