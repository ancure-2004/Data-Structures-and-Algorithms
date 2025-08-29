#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void func(int ind, string s, vector<string> path, vector<vector<string>> &res){

    if(ind == s.size()){
        res.push_back(path);
        return ;
    }

    for(int i = ind; i < s.size(); i++){
        if(isPalindrome(s, ind, i)){
            path.push_back(s.substr(ind, i - ind + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

int main(){

    string s = "aabb";
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}