#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string common = strs[0];
        
        for(int i = 1; i < n; i++){
            string word = strs[i];
            int j = 0;
            while(j < word.size() && j < common.size() && common[j] == word[j]){
                j++;
            }
            if(j == 0){
                return "";
            }
            common = common.substr(0, j);
        }
        return common;
    }
};