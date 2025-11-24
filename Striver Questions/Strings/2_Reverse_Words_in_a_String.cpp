#include <bits/stdc++.h>
using namespace std;

//Extreme Naive Solution

class Solution {
public:
    string removeInitial(string s){
        int i = 0, cnt = 0;
        while(i < s.size() && s[i] == ' '){
            cnt++;
            i++;
        }

        return s.substr(cnt, s.size());
    }

    string reverseWords(string s) {
        s = removeInitial(s);
        int n = s.size();

        vector<string> ans;
        string word = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(!word.empty()){
                    ans.push_back(word);
                    word.clear();
                    continue;
                }
            }
            else{
                word += s[i];
            }
        }

        if(!word.empty()) ans.push_back(word);

        reverse(ans.begin(), ans.end());

        string result = "";
        for(auto it : ans){
            string word = it + " ";
            result += word;
        }

        return result.substr(0, result.size() - 1);
    }
};

//Optimized Solution

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;

            int j = i;
            while(i >= 0 && s[i] != ' ') i--;

            if(!ans.empty()) ans += ' ';
            ans +=  s.substr(i + 1, j - i);
        }

        return ans;
    }
};