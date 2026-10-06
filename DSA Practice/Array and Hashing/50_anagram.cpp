#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        int map1[26] = {0};

        for(int i = 0; i < n; i++) map1[s[i] - 'a']++;
        for(int i = 0; i < m; i++) map1[t[i] - 'a']--;

        for(int i = 0; i < 26; i++){
            if(map1[i] != 0) return false;
        }

        return true;
    }
};