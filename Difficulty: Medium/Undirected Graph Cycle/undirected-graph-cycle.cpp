//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the parent of a node with path compression
    int findParent(int node, vector<int> &parent) {
        if (parent[node] == -1)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    // Function to union two subsets
    void unionSet(int u, int v, vector<int> &parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv)
            parent[pu] = pv;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V, -1);  // Initially, each node is its own parent
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu == pv)
                return true;  // Cycle found
            unionSet(u, v, parent);
        }
        return false;  // No cycle
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends