#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = 4;
    int prev1 = arr[0];
    int prev2 = 0;
    int curr = 0;

    for (int i = 1; i < n; i++)
    {   
        int pick = arr[i];
        if(i > 1)
            pick += prev2;
        
        int notPick = 0 + prev1;
        curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;
    }
    cout << curr;

    return 0;
}