#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";
    int n = s1.size();
    int m = s2.size();

    vector<bool> prev(m + 1, false);
    vector<bool> curr(m + 1, false);

    prev[0] = true;

    for(int j = 1; j <= m; j++){
        prev[j] = false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            int flag = true;
            for(int x = 0; x < i; x++){
                if(s1[x] != '*')
                    flag = false;
                    break;
            }
            curr[0] = flag;

            if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                curr[j] = prev[j - 1];

            else if(s1[i - 1] == '*'){
                curr[j] = prev[j] || curr[j - 1];
            }
            else
                curr[j] = false;
        }
        prev = curr;
    }

    prev[m] ? cout << "true" : cout << "false";

    return 0;
}