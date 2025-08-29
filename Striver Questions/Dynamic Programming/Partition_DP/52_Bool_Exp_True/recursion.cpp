#include <bits/stdc++.h>
using namespace std;

int ways(int i, int j, int isTrue, string s){
    if(i > j) return 0;
    if(i == j){
        if(isTrue == 1){
            return s[i] == 'T';
        }
        else return s[i] == 'F';
    }

    int way = 0;
    for(int ind = i + 1; ind <= j - 1; ind = ind + 2){
        int LT = ways(i, ind - 1, 1, s);
        int LF = ways(i, ind - 1, 0, s);
        int RT = ways(ind + 1, j, 1, s);
        int RF = ways(ind + 1, j, 0, s);
        
        if(s[ind] == '&'){
            if(isTrue){
                way += LT * RT;
            }
            else{
                way += (LT * RF) + (LF * RT) + (LF * RF);
            }
        }

        else if(s[ind] == '|'){
            if(isTrue){
                way += (LT * RF) + (LF * RT) + (LT * RT);
            }
            else{
                way += (LF * RF);
            }
        }

        else{
            if(isTrue){
                way += (LT * RF) + (LF * RT);
            }
            else{
                way += (LT * RT) + (LF * RF);
            }
        }
    }

    return way;
}

int main() {

    string s = "T^F|T&F^T|F";
    int n = s.size();

    int trueWays = ways(0, n - 1, 1, s);
    cout << trueWays;

    return 0;
}