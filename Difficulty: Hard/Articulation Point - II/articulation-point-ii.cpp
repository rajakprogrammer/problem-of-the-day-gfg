//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low,
             vector<bool>& visited, vector<bool>& isArticulation, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, isArticulation, time);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else {
                low[u] = min(low[u], disc[v]); // Back edge
            }
        }

        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isArticulation(V, false);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isArticulation, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) result.push_back(i);
        }

        if (result.empty()) return {-1}; // As per usual problem constraints
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends