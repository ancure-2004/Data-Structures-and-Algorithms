#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string> words;

        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++;

            string temp = ""; 

            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }

            if(!temp.empty()){
                words.push_back(temp);
            }
        }

        reverse(words.begin(), words.end());

        string ans = "";
        for(int i = 0; i < words.size(); i++){
            ans += words[i];

            if(i != words.size() - 1){
                ans += ' ';
            }
        }

        return ans;
    }
};

//Optimal Approach
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string ans = "";
        int i = s.size() - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;

            int j = i;
            while(i >= 0 && s[i] != ' ') i--;

            if(!ans.empty()) ans += ' ';
            ans += s.substr(i + 1, j - i);
        }

        return ans;
    }
};