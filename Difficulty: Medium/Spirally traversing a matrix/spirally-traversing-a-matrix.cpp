//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        // Function to perform spiral traversal of a 2D matrix
   int n = mat.size();    // Number of rows
    if (n == 0) return {}; // Handle edge case: Empty matrix
    int m = mat[0].size(); // Number of columns

    // Initialize boundaries for traversal
    int left = 0, right = m - 1;  // Leftmost and rightmost column
    int top = 0, bottom = n - 1; // Topmost and bottommost row

    vector<int> result; // Vector to store the spiral order

    // Continue traversal while there are unvisited elements within boundaries
    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; i++) {
            result.push_back(mat[top][i]);
        }
        top++; // Move the top boundary down after processing the top row

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(mat[i][right]);
        }
        right--; // Move the right boundary left after processing the right column

        // Traverse from right to left across the bottom row (if still within boundaries)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(mat[bottom][i]);
            }
            bottom--; // Move the bottom boundary up after processing the bottom row
        }

        // Traverse from bottom to top along the left column (if still within boundaries)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(mat[i][left]);
            }
            left++; // Move the left boundary right after processing the left column
        }
    }

    // Return the result vector containing elements in spiral order
    return result;
}
};

        

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends