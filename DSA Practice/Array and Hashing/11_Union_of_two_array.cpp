#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i = 0;
        int j = 0;
        vector<int> result;

        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                if(result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
            else {
                if(a[i] < b[j]) {
                    if(result.empty() || result.back() != a[i]) {
                        result.push_back(a[i]);
                    }
                    i++;
                }
                else {
                    if(result.empty() || result.back() != b[j]) {
                        result.push_back(b[j]);
                    }
                    j++;
                }
            }
        }

        while(i < a.size()) {
            if(result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }

        while(j < b.size()) {
            if(result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }

        return result;
    }
};