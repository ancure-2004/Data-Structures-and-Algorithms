#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = 4;
    vector<int> dp(n, 0);

    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {   
        //My way try if it can pass all the test case
        //int pick = 0;
        // if(i - 2 > 0)
        //     pick = dp[i - 2] + arr[i];
        
        // Striver's way check this also if able to pass all the test case
        int pick = arr[i];
        if(i > 1)
            pick += dp[i - 2];
        
        int notPick = 0 + dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    cout << dp[n - 1];

    return 0;
}