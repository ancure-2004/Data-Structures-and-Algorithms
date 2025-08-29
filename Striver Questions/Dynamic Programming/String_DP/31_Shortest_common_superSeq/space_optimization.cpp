#include <bits/stdc++.h>
using namespace std;

int LCS(int n, int m, string s1, string s2, vector<int> &prev){

    vector<int> curr(m + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }

            else curr[j] = max(prev[j] , curr[j - 1]);
        }
        prev = curr;
    }

    return prev[m];
}

int main() {

    string s1 = "bleed";
    string s2 = "blood";
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);

    int lcs = LCS(n, m, s1, s2, prev);

    // Length of supersequence
    int length = n + m - lcs;
    cout << length << endl;

    int i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            ans += s1[i - 1];
            i--, j--;
        }
        else if(prev[j] > prev[j - 1]){
            ans += s1[i - 1];
            i--;
        }
        else{
            ans += s2[j - 1];
            j--;
        }
    }

    while(i > 0){
        ans += s1[i - 1];
        i--;
    }

    while(j > 0){
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}