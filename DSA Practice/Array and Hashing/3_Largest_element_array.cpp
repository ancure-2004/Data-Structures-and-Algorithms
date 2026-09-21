#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largest_element = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest_element){
                largest_element = arr[i];
            }
        }
        
        return largest_element;
    }
};
