#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int minLen = 100007;
        int sIndex = -1;

        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            for(int j = 0; j < m; j++) hash[t[j]]++;

            int cnt = 0;

            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;

                if(cnt == m){
                    if(j - i + 1 < minLen){
                        minLen = j - i + 1;
                        sIndex = i;
                        break;
                    }
                }
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

//Optimal Solution
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l = 0;
        int r = 0;
        int minLen = 100007;

        int cnt = 0;
        int hash[256] = {0};
        int sIndex = -1;

        for(int i = 0; i < m; i++) hash[t[i]]++;

        while(r < n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r - l + 1 < minLen){
                    sIndex = l;
                    minLen = r - l + 1;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;

                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};