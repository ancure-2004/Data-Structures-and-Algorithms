#include <bits/stdc++.h>
using namespace std;

int climbing(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;

    int left = climbing(n - 1);
    int right = climbing(n - 2);
    
    return left + right;
}

int main(){

    int n = 3;
    cout << climbing(n);

    return 0; 
}