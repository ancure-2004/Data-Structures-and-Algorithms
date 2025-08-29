#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "abcd";
    string s2 = "anc";
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    //base case for tabulation shifting right
    for(int j = 0; j <= m; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }

            else curr[j] = max(prev[j] , curr[j - 1]);
        }
        prev = curr;
    }

    // Formula for operations see notes
    int ans = n + m - (2 * prev[m]);
    cout << ans;

    return 0;
}