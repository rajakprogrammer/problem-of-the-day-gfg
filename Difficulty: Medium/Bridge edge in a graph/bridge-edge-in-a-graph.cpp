//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Create adjacency list
        vector<int> adj[V];
        for (auto &edge : edges) {
            if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c)) {
                // Skip the edge (c, d) temporarily
                continue;
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: DFS from c
        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        // Step 3: If d is not visited, then (c,d) is a bridge
        return !visited[d];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends