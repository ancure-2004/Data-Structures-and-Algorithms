#include <bits/stdc++.h>
using namespace std;

//space optimization
int main()
{
    int n = 4;
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;

    int height[] = {10, 20, 30, 10};

    for (int i = 1; i < n; i++)
    {
        int left = abs(height[i] - height[i - 1]) + prev1;

        int right = INT_MAX;
        if (i > 1)
            right = abs(height[i] - height[i - 2]) + prev2;

        curr = min(left, right);

        prev2 = prev1;
        prev1 = curr;
    }

    cout << curr ;

    return 0;
}