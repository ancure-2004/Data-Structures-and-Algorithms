#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleBloom(int mid, vector<int> bloomDay, int k){
        int bouquets = 0;
        int cnt = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid ) cnt++;

            else{
                bouquets += (cnt/k);
                cnt = 0;
            }
        }

        bouquets += (cnt/k);

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int maxDay = INT_MIN;
        for(int i = 0; i < n; i++){
            maxDay = max(maxDay, bloomDay[i]);
        }

        int low = 1;
        int high = maxDay;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possibleBloom(mid, bloomDay, k) >= m){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};