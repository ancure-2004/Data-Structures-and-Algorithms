#include <bits/stdc++.h>
using namespace std;

int editDistance(int i, int j, string s1, string s2){
    if(j < 0) return i + 1;
    if(i < 0) return j + 1;

    if(s1[i] == s2[j]){
        return editDistance(i - 1, j - 1, s1, s2);
    }

    int insertion = 1 + editDistance(i, j - 1, s1, s2);
    int deletion = 1 + editDistance(i - 1, j, s1, s2);
    int replace = 1 + editDistance(i - 1, j - 1, s1, s2);

    return min(insertion, min(deletion, replace));
}

int main() {

    string s1 = "horse";
    string s2 = "ros";
    int n = s1.size();
    int m = s2.size();

    int minWays = editDistance(n - 1, m - 1, s1, s2);
    cout << minWays;

    return 0;
}