#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "T^F|T&F^T|F";
    int n = s.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, 0)));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i > j) continue;

            for(int isTrue = 0; isTrue <= 1; isTrue++){

                if(i == j){
                    if(isTrue == 1){
                        dp[i][j][isTrue] = (s[i] == 'T');
                    }

                    else dp[i][j][isTrue] = (s[i] == 'F');
                    continue;
                }

                int way = 0;

                for(int ind = i + 1; ind <= j - 1; ind = ind + 2){

                    int LT = dp[i][ind - 1][1];
                    int LF = dp[i][ind - 1][0];
                    int RT = dp[ind + 1][j][1];
                    int RF = dp[ind + 1][j][0];

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
                dp[i][j][isTrue] = way;
            }
        }
    }

    cout << dp[0][n - 1][1];

    return 0;
}