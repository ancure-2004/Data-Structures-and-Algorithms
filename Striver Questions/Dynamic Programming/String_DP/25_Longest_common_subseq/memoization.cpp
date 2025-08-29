#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
    }

    return dp[i][j] = max(lcs(i - 1, j , s1, s2, dp), lcs(i, j - 1, s1, s2, dp));
}

int main() {

    string s1 = "abcde";
    string s2 = "ace";
    int i = s1.size();
    int j = s2.size();

    vector<vector<int>> dp(i, vector<int> (j, -1));

    int length = lcs(i - 1, j - 1, s1, s2, dp);
    cout << length;

    return 0;
}