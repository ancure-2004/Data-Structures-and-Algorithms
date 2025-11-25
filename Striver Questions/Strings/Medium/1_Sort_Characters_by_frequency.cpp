#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool comp(pair<int, char> &a, pair<int, char> &b){
        return a.first > b.first;
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c] += 1;

        vector<pair<int, char>> arr;
        for (auto &p : cnt)
            arr.push_back({p.second, p.first});

        sort(arr.begin(), arr.end(), comp);

        string ans;
        for (auto &p : arr)
            ans.append(p.first, p.second);
        return ans;
    }
};