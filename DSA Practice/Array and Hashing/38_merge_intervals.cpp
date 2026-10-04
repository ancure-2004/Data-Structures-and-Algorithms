#include<bits/stdc++.h>
using namespace std;

//navie approach

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]){
            return true;
        }
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            vector<int> pairToCheck = result.back();
            if(pairToCheck[1] >= intervals[i][0]){
                int start = min(pairToCheck[0], intervals[i][0]);
                int end = max(pairToCheck[1], intervals[i][1]);
                vector<int> newIntervals = {start, end};
                result.back() = newIntervals;
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};


// Good Approach
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0){
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());

        vector<int> tempIntervals = intervals[0];
        for(auto it: intervals){
            if(it[0] <= tempIntervals[1]){
                tempIntervals[1] = max(tempIntervals[1], it[1]);
            }
            else{
                mergedIntervals.push_back(tempIntervals);
                tempIntervals = it;
            }
        }
        mergedIntervals.push_back(tempIntervals);
        return mergedIntervals;
    }
};