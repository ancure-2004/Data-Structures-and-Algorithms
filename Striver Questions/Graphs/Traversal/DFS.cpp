#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    graph(int n, int m, vector<vector<int>> &adj){
        cout << "Enter the edges: " << endl;
        
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int node, vector<int> &ans, vector<vector<int>> & adj, int vis[]){
        vis[node] = 1;
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, ans, adj, vis);
            }
        }
    }

    vector<int> traversal(int V, vector<vector<int>> &adj){
        int vis[V + 1] = {0};
        int start = 1;
        vector<int> ans;
        dfs(start, ans, adj, vis);

        return ans;
    }

    void printTraversedGraph(vector<int> &dfs){
        cout << "The BFS Traversal of Graph is: " << endl;
        for(int i = 0; i < dfs.size(); i++){
            cout << dfs[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    int n, m;
    cout << "Enter the no. of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    graph g1(n, m, adj);
    
    vector<int> dfs = g1.traversal(n, adj);

    g1.printTraversedGraph(dfs);

    return 0;
}