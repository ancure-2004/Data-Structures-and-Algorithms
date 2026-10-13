#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> constructLPS(vector<int>& b) {
        int m = b.size();
        vector<int> lps(m, 0);

        for(int i = 1; i < m; i++){
            int prevIndex = lps[i - 1];

            while(prevIndex > 0 && b[i] != b[prevIndex]){
                prevIndex = lps[prevIndex - 1];
            }

            lps[i] = prevIndex + (b[i] == b[prevIndex]);
        }

        return lps;
    }

    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<int> lps = constructLPS(b);
        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && a[i] != b[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return result;
    }
};