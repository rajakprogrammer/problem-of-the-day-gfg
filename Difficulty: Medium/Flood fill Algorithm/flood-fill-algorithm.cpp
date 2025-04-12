//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        // Base case: if out of bounds or color does not match original
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != color)
            return;

        // Change the color
        image[x][y] = newColor;

        // Visit all four directions
        dfs(image, x + 1, y, color, newColor); // down
        dfs(image, x - 1, y, color, newColor); // up
        dfs(image, x, y + 1, color, newColor); // right
        dfs(image, x, y - 1, color, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];

        // Avoid infinite loop if newColor is same as originalColor
        if (originalColor != newColor)
            dfs(image, sr, sc, originalColor, newColor);

        return image;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends