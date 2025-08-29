#include <bits/stdc++.h>
using namespace std;

bool wildMatching(int i, int j, string s1, string s2, vector<vector<int>> &dp){

    if(i < 0 && j < 0) return true;
    if(i < 0 &&  j >= 0) return false;
    if(j < 0 && i >= 0){
        for(int x = 0; x <= i; x++){
            if(s1[x] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = wildMatching(i - 1, j - 1, s1, s2,dp);

    if(s1[i] == '*'){
        return dp[i][j] = wildMatching(i - 1, j, s1, s2, dp) || wildMatching(i, j - 1, s1, s2, dp);
    }

    return dp[i][j] = false;
}

int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    bool matched = wildMatching(n - 1, m - 1, s1, s2, dp);
    matched ? cout << "true" : cout << "false";

    return 0;
}