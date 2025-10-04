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

    vector<int> traversal(int V, vector<vector<int>> &adj){
        int vis[V + 1] = {0};
        vis[1] = 1;
        queue <int > q;
        q.push(1);
        vector<int> bfs;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }

    void printTraversedGraph(vector<int> &bfs){
        cout << "The BFS Traversal of Graph is: " << endl;
        for(int i = 0; i < bfs.size(); i++){
            cout << bfs[i] << " ";
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
    
    vector<int> bfs = g1.traversal(n, adj);

    g1.printTraversedGraph(bfs);

    return 0;
}