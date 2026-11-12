#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long takenHours(vector<int> piles, int mid){
        long long totalHrs = 0;

        for(int i = 0; i < piles.size(); i++){
            totalHrs += ceil((double)piles[i]/mid);
        }

        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxBananas = INT_MIN;

        for(int i = 0; i < n; i++){
            maxBananas = max(maxBananas, piles[i]);
        }


        int start = 1;
        int end = maxBananas;

        int ans = 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;

            long long totalHrs = takenHours(piles, mid);

            if(totalHrs <= h){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};