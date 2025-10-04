#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int adj[n+1][m+1];
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        adj[l][r] = 1;
        adj[r][l] = 1;
    }

    return 0;
}