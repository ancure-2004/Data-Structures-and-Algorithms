#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){

    int i = 0;
    int j = s.size() - 1;
    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}

int partition(int i, string s, vector<int> &dp){
    if(i == s.size())
        return 0;

    if(dp[i] != -1){
        return dp[i];
    }

    string temp = "";
    int min_cost = INT_MAX;
    for(int j = i; j < s.size(); j++){
        temp += s[j];
        if(isPalindrome(temp)){
            int cost = 1 + partition(j + 1, s, dp);
            min_cost = min(min_cost, cost);
        }
    }

    return dp[i] = min_cost;
}

int main() {

    string s = "bababcbadcede";

    vector<int> dp(s.size(), -1);
    
    int cost = partition(0, s, dp) - 1;
    cout << cost;

    return 0;
}