#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int floorVal = -1;
        int ceilVal = -1;
        
        for (int num : arr) {
            if (num <= x && (floorVal == -1 || num > floorVal)) {
                floorVal = num;
            }
        
            if (num >= x && (ceilVal == -1 || num < ceilVal)) {
                ceilVal = num;
            }
        }
        
        return {floorVal, ceilVal};
    }
};