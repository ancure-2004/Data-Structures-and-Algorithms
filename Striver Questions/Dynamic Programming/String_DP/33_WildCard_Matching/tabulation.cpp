#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";
    int n = s1.size();
    int m = s2.size();

    vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));

    dp[0][0] = true;

    for(int j = 1; j <= m; j++){
        dp[0][j] = false;
    }

    for(int i = 1; i <=n; i++){
        int flag = true;
        for(int x = 0; x < i; x++){
            if(s1[x] != '*')
                flag = false;
                break;
        }
        dp[i][0] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if(s1[i - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else dp[i][j] = false;
        }
    }

    dp[n][m] ? cout << "true" : cout << "false";

    return 0;
}