#include <bits/stdc++.h>
using namespace std;

//tabulation
int main()
{
    int n = 4;
    vector<int> dp(n + 1, 0);

    int height[] = {10, 20, 30, 10};

    for (int i = 1; i < n; i++)
    {
        int left = abs(height[i] - height[i - 1]) + dp[i - 1];

        int right = INT_MAX;
        if (i > 1)
            right = abs(height[i] - height[i - 2]) + dp[i - 2];

        dp[i] = min(left, right);
    }

    cout << dp[n - 1] ;

    return 0;
}