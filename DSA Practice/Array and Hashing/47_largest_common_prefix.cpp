#include<bits/stdc++.h>
using namespace std;

//Naive Approach
class Solution {
public:
    bool checkPrefix(char prefix, int place, vector<string> strs){
        
        for(int i = 0; i < strs.size(); i++){
            
            if(place >= strs[i].size()) return false;

            char toCheck = strs[i][place];
            
            if(toCheck != prefix){
                return false;
            }
        }

        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        int n = strs.size();
        int m = strs[0].size();

        string ans = "";
        for(int i = 0; i < m; i++){
            if(checkPrefix(strs[0][i], i, strs) == false){
                break;
            }
            ans += strs[0][i];
        }

        return ans;
    }
};

//Optimal Approach time complexity is same, in case of understandablity and best practices
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