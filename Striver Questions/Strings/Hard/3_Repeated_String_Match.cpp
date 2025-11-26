#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        if(a == b) return 1;
        if(a.find(b) != string::npos){
            return 1;
        }

        string temp = a;
        int rep = 1;
        while(temp.size() < b.size()){
            rep++;
            temp += a;
        }

        if(temp.find(b) != string::npos){
            return rep;
        }

        temp += a;
        if(temp.find(b) != string::npos){
            rep++;
            return rep;
        }

        return -1;
    }
};