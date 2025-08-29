#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string s1, string s2){
    if(i < 0 || j < 0) return 0;

    if(s1[i] == s2[j]){
        return 1 + lcs(i - 1, j - 1, s1, s2);
    }

    return max(lcs(i - 1, j , s1, s2), lcs(i, j - 1, s1, s2));
}

int main() {

    string s1 = "abcde";
    string s2 = "ace";
    int i = s1.size();
    int j = s2.size();

    int length = lcs(i - 1, j - 1, s1, s2);
    cout << length;

    return 0;
}