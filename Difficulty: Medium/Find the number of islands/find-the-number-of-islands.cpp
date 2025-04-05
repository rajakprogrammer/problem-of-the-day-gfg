//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary and visited/sea check
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 'L') {
            return;
        }

        // Mark as visited
        grid[i][j] = '0';

        // All 8 directions (including diagonals)
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int dir = 0; dir < 8; ++dir) {
            dfs(grid, i + dx[dir], j + dy[dir]);
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'L') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends