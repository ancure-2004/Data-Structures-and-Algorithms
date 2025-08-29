#include <bits/stdc++.h>
using namespace std;

int max_points(int days, int last, int points[][3]){
    if(days == 0){
        int maxi = INT_MIN;
        for(int i = 0; i <= 2; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for(int i = 0; i <= 2; i++){
        if(i != last){
            int curr_points = points[days][i] + max_points(days - 1, i, points);
            maxi = max(curr_points, maxi);
        }
    }

    return maxi;
}

int main(){
    int points[4][3] = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int days = 4;
    int task = 3;

    cout << max_points(days - 1, 3, points);

    return 0;
}