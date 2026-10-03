#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0] = {1};

        for(int i = 1; i < numRows; i++){
            result[i].resize(i + 1);
            result[i][0] = 1;
            int currIndx = 1;
            for(int j = 0; j < result[i - 1].size(); j++){
                int sum = result[i - 1][j];
                if(j + 1 < result[i - 1].size()){
                    sum += result[i - 1][j + 1];
                }
                result[i][currIndx++] = sum;
            }
        }

        return result;
    }
};