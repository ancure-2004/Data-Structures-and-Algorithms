#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[2][3] = {{5, 9 , 6}, {11, 5, 2}};

    vector<int> prev(3);

    for(int n = 0; n < 2; n++){

        vector<int> curr(3);

        for(int m = 0; m < 3; m++){

            if(m == 0 && n == 0) curr[0] = arr[0][0];

            else {

                int UP = arr[n][m], LEFT = arr[n][m];

                if(n > 0 ) UP += prev[m];
                else UP += 1e9;

                if(m > 0) LEFT += curr[m - 1];
                else LEFT += 1e9;

                curr[m] = min(UP, LEFT);
            }
        }

        prev = curr;
    }

    cout << prev[2];

    return 0;
}