#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = -1;
        int second_largest = -1;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                second_largest = largest;
                largest = arr[i];
            }
            
            else if(second_largest < arr[i] && arr[i] < largest){
                second_largest = arr[i];
            }
        }
        
        return second_largest;
    }
};