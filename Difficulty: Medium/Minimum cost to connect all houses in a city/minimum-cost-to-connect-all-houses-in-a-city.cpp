//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    struct Edge {
        int u, v, cost;
        bool operator<(const Edge& other) const {
            return cost < other.cost;
        }
    };

    int find(int x, vector<int>& parent) {
        if (x != parent[x])
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<Edge> edges;

        // Build all pairwise edges with Manhattan distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                edges.push_back({i, j, cost});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;

        int totalCost = 0, edgesUsed = 0;
        for (const auto& e : edges) {
            int pu = find(e.u, parent);
            int pv = find(e.v, parent);
            if (pu != pv) {
                unite(e.u, e.v, parent, rank);
                totalCost += e.cost;
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }

        return totalCost;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends