#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int maxCnt = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }

            else if(s[i] == ')' && cnt != 0){
                cnt --;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};