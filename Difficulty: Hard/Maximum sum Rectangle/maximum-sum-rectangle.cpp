#include <vector>       // for using vector
#include <climits>      // for INT_MIN (minimum integer value)
#include <algorithm>    // for max() function
using namespace std;

class Solution {
public:
    
    // Kadane's Algorithm for 1D array: returns the maximum subarray sum
    int kadane(vector<int>& arr) {
        int max_sum = arr[0];     // Initialize max_sum with first element
        int curr_sum = arr[0];    // Initialize current sum with first element

        // Loop through remaining elements
        for (int i = 1; i < arr.size(); i++) {
            // Decide whether to add current element or start fresh from current element
            curr_sum = max(arr[i], curr_sum + arr[i]);
            // Update maximum sum so far
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;   // Return maximum subarray sum
    }

    // Function to find the maximum sum rectangle in a 2D matrix
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();        // Number of rows
        int m = mat[0].size();     // Number of columns
        int ans = INT_MIN;         // Initialize final answer with the smallest possible value

        // Outer loop: fix the top row of the submatrix
        for (int top = 0; top < n; top++) {
            vector<int> temp(m, 0);  // Temp array to store column sums

            // Inner loop: move the bottom row from top to last row
            for (int bottom = top; bottom < n; bottom++) {
                // Add current row's values to temp[] to build the column-wise sum
                for (int col = 0; col < m; col++) {
                    temp[col] += mat[bottom][col];
                }

                // Use Kadane's algorithm to find the best (maximum sum) subarray in temp[]
                int currentMax = kadane(temp);

                // Update the overall maximum answer if this is greater
                ans = max(ans, currentMax);
            }
        }

        return ans;  // Return the maximum sum of any submatrix
    }
};
