#include <bits/stdc++.h>
using namespace std;

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

bool compare(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;
    int first = 0;
    int second = 0;

    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else{
            first++;
        }

    }

    if(first == s1.size() && second == s2.size()){
        return true;
    }

    return false;
}

int main() {

    vector<string> arr = {"a","b", "ba", "bca", "bda", "bdca"};
    int n = arr.size();

    sort(arr.begin(), arr.end(), comp);

    vector<int> dp(n + 1, 1);

    int maxi = 1;
    for(int ind = 0; ind < n; ind++){
        for(int prevInd = 0; prevInd < ind; prevInd++){
            if(compare(arr[ind], arr[prevInd])){
                dp[ind] = max(dp[ind], 1 + dp[prevInd]);
            }
        }
        maxi = max(dp[ind], maxi);
    }

    cout << maxi;

    return 0;
}