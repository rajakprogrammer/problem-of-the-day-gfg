//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Create adjacency list
        vector<pair<int, int>> adj[V]; // adj[u] = {v, weight}
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w)); // Remove for directed graph
        }

        // Step 2: Min heap and distance array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        // Step 3: Start from src
        dist[src] = 0;
        pq.push(make_pair(0, src)); // {distance, node}

        // Step 4: Dijkstra's algorithm
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int weight = adj[u][i].second;

                if (currDist + weight < dist[v]) {
                    dist[v] = currDist + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends