#include <bits/stdc++.h>
using namespace std;

int ways(int i, int j, int isTrue, string s, vector<vector<vector<int>>> &dp){
    if(i > j) return 0;
    if(i == j){
        if(isTrue == 1){
            return s[i] == 'T';
        }
        else return s[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    int way = 0;
    for(int ind = i + 1; ind <= j - 1; ind = ind + 2){
        int LT = ways(i, ind - 1, 1, s, dp);
        int LF = ways(i, ind - 1, 0, s, dp);
        int RT = ways(ind + 1, j, 1, s, dp);
        int RF = ways(ind + 1, j, 0, s, dp);
        
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

    return dp[i][j][isTrue] = way;
}

int main() {

    string s = "T^F|T&F^T|F";
    int n = s.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));


    int trueWays = ways(0, n - 1, 1, s, dp);
    cout << trueWays;

    return 0;
}