#include <bits/stdc++.h>
using namespace std;

int distinct(int i, int j, string s1, string s2){
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(s1[i] == s2[j]){
        return distinct(i - 1, j - 1, s1, s2) + distinct(i - 1, j, s1, s2);
    }
    else
        return distinct(i - 1, j, s1, s2);
}

int main() {

    string s1 = "babgbag";
    string s2 = "bag";
    int n = s1.size();
    int m = s2.size();

    int distinct_ways = distinct(n - 1, m - 1, s1, s2);
    cout << distinct_ways;

    return 0;
}