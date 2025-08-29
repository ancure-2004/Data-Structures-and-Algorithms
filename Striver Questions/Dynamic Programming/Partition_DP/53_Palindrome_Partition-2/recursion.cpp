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

int partition(int i, string s){
    if(i == s.size())
        return 0;

    string temp = "";
    int min_cost = INT_MAX;
    for(int j = i; j < s.size(); j++){
        temp += s[j];
        if(isPalindrome(temp)){
            int cost = 1 + partition(j + 1, s);
            min_cost = min(min_cost, cost);
        }
    }

    return min_cost;
}

int main() {

    string s = "bababcbadcede";
    
    int cost = partition(0, s) - 1;
    cout << cost;

    return 0;
}