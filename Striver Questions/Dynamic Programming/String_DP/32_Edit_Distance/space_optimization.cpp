#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "intention";
    string s2 = "execution";
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            curr[0] = i;

            if(s1[i - 1] == s2[j - 1]){
                curr[j] = prev[j - 1];
            }
            else{
                int insertion = 1 + curr[j - 1];
                int deletion = 1 + prev[j];
                int replace = 1 + prev[j - 1];

                curr[j] = min(insertion, min(deletion, replace));
            }
        }
        prev = curr;
    }

    cout << prev[m];

    return 0;
}