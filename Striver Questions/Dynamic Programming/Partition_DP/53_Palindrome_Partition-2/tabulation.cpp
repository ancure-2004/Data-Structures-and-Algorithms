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

int main() {

    string s = "bababcbadcede";

    vector<int> dp(s.size() + 1, -1);

    for(int i = s.size() - 1; i >= 0; i--){
        string temp = "";
        int min_cost = INT_MAX;
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cost = 1 + dp[j + 1];;
                min_cost = min(min_cost, cost);
            }
        }
        dp[i] = min_cost;
    }
    
    cout << dp[0];

    return 0;
}