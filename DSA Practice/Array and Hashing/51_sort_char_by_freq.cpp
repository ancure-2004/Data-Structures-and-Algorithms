#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(pair<int, char> &a, pair<int, char> &b){
        return a.first > b.first;
    }

    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); i++) hash[s[i]]++;

        vector<pair<int, char>> freq;
        for(auto &[c, cnt] : hash) freq.push_back({cnt, c});

        sort(freq.begin(), freq.end(), comp);
        
        string ans = "";
        for(int i = 0; i < freq.size(); i++){
            while(freq[i].first != 0){
                ans += freq[i].second;
                freq[i].first--;
            }
        }

        return ans;
    }
};