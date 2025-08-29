#include <bits/stdc++.h>
using namespace std;

bool wildMatching(int i, int j, string s1, string s2){

    if(i < 0 && j < 0) return true;
    if(i < 0 &&  j >= 0) return false;
    if(j < 0 && i >= 0){
        for(int x = 0; x <= i; x++){
            if(s1[x] != '*')
                return false;
        }
        return true;
    }

    if(s1[i] == s2[j] || s1[i] == '?')
        return wildMatching(i - 1, j - 1, s1, s2);

    if(s1[i] == '*'){
        return wildMatching(i - 1, j, s1, s2) || wildMatching(i, j - 1, s1, s2);
    }

    return false;
}

int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";
    int n = s1.size();
    int m = s2.size();

    bool matched = wildMatching(n - 1, m - 1, s1, s2);
    matched ? cout << "true" : cout << "false";

    return 0;
}