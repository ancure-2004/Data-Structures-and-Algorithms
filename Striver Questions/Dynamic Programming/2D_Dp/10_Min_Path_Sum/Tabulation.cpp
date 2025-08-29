#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[2][3] = {{5, 9 , 6}, {11, 5, 2}};
    vector<vector<int>> dp (2 + 1, vector<int> (3 + 1, 0));

    for(int n = 0; n < 2; n++){
        for(int m = 0; m < 3; m++){

            if(m == 0 && n == 0) dp[0][0] = arr[0][0];

            else {

                int UP = arr[n][m], LEFT = arr[n][m];

                if(n > 0 ) UP += dp[n - 1][m];
                else UP += 1e9;

                if(m > 0) LEFT += dp[n][m - 1];
                else LEFT += 1e9;

                dp[n][m] = min(UP, LEFT);
            }
        }
    }

    cout << dp[1][2];

    return 0;
}