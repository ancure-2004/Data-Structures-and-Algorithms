#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int knowsMe[n] = {0};
        int iknow[n] = {0};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1 && i != j){
                    knowsMe[j]++;
                    iknow[i]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(knowsMe[i] == n - 1 && iknow[i] == 0){
                return i;
            }
        }
        
        return -1;
    }
};

//Optimal Solution
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        int top = 0;
        int down = n - 1;
        
        while(top < down){
            if(mat[top][down] == 1){
                top++;
            }
            else if(mat[down][top]){
                down--;
            }
            else{
                top++, down--;
            }
        }
        
        if(top > down) return -1;
        
        for(int i = 0; i < n; i++){
            if(i == top) continue;
            
            if(mat[top][i] == 0 && mat[i][top] == 1){
                continue;
            }
            
            else return -1;
        }
        
        return top;
    }
};