#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "horse";
    string s2 = "ros";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 0; i <= n; i++) dp[i][0] = i;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                int insertion = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(insertion, min(deletion, replace));
            }
        }
    }

    cout << dp[n][m];

    return 0;
}