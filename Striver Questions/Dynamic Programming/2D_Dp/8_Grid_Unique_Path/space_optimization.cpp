#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int m = 3;
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0){
                curr[j] = 1;
                continue;
            }
            
            int UP = 0, LEFT = 0;
            if(i - 1 >= 0) UP = prev[j];
            if(j - 1 >= 0) LEFT = curr[j - 1]; 
            curr[j] = UP + LEFT;
        }
        prev = curr;
    }
    cout << prev[m-1];

    return 0;
}