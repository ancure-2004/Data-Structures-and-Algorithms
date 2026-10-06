#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            string rotated = s.substr(i) + s.substr(0, i);

            if(rotated == goal) return true;
        }

        return false;
    }
};

//Optimal Approach
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        int m = s.size();

        if(m != n) return false;

        string combined = s + s;
        int combinedsize = combined.size();
        
        for(int i = 0; i < n; i++){
            string rotated = combined.substr(i, n);
            if(rotated == goal){
                return true;
            }
        }

        return false;
    }
};