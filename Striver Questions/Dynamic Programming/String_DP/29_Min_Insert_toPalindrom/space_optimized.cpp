#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "codingninjas";
    int n = s1.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    string s2 = s1;
    reverse(s2.begin(), s2.end());

    //base case for tabulation shifting right
    for(int j = 0; j <= n; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }

            else curr[j] = max(prev[j] , curr[j - 1]);
        }
        prev = curr;
    }

    // Minimum insertions answer
    int ans  = s1.length() - prev[n];
    cout << ans;

    return 0;
}