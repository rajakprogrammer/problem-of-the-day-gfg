//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q; // Queue to store rotten oranges
        int freshCount = 0, time = 0;
        
        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Step 1: Push all initially rotten oranges into the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Step 2: Perform BFS
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            time++; // Each level of BFS represents 1 minute

            for (int i = 0; i < size; i++) {
                pair<int, int> cell = q.front(); // Get the front element
                q.pop();
                
                int r = cell.first, c = cell.second; // Extract row and column manually
                
                // Explore the four possible directions
                for (int d = 0; d < 4; d++) {
                    int newRow = r + directions[d].first;
                    int newCol = c + directions[d].second;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols 
                        && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2; // Mark fresh orange as rotten
                        freshCount--;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        // If freshCount > 0, some oranges are still fresh, return -1
        return freshCount == 0 ? time : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends