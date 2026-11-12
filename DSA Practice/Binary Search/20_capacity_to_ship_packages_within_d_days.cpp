#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int packagesDays(int mid, vector<int> weights){
        int days = 1;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= mid){
                sum = sum + weights[i];
            }
            else{
                days++;
                sum = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxi = INT_MIN;
        int total = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, weights[i]);
            total += weights[i];
        }

        int low = maxi;
        int high = total;

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(packagesDays(mid, weights) <= days){
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