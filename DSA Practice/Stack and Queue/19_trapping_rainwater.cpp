#include<bits/stdc++.h>
using namespace std;

//Prefix and suffix approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix(n);
        prefix[0] = height[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        vector<int> suffix(n);
        suffix[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            count += min(prefix[i], suffix[i]) - height[i];
        }

        return count;
    }
};


//Two pointers approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int total = 0;
        int leftmax = 0; 
        int rightmax = 0;
        int l = 0;
        int r = n - 1;

        while(l < r){
            if(height[l] <= height[r]){
                if(leftmax > height[l]){
                    total += leftmax - height[l];
                }
                else{
                    leftmax = height[l];
                }

                l = l + 1;
            }
            else{
                if(rightmax > height[r]){
                    total += rightmax - height[r];
                }
                else{
                    rightmax = height[r];
                }

                r = r - 1;
            }
        }

        return total;
    }
};