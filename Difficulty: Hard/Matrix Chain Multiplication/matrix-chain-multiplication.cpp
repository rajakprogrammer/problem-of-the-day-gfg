//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp; // Memoization table to store intermediate results

    // Recursive helper function to find the minimum cost
    int helper(int start, int end, vector<int> &arr) {
        // Base Case: If only one matrix is left (end - start == 1), no multiplication needed
        if (end - start == 1) return 0;  
        
        // If already computed, return the stored value to avoid redundant calculations
        if (dp[start][end] != -1) return dp[start][end]; 

        int ans = INT_MAX;  // Initialize answer with maximum possible value

        // Try different partitions for matrix multiplication
        for (int k = start + 1; k < end; k++) {
            int left = helper(start, k, arr);  // Compute cost for left subproblem
            int right = helper(k, end, arr);  // Compute cost for right subproblem
            
            // Calculate the multiplication cost for the current partition
            ans = min(ans, left + right + arr[start] * arr[k] * arr[end]);
        }

        // Store and return the minimum cost for multiplying matrices from 'start' to 'end'
        return dp[start][end] = ans; 
    }

    // Function to initialize DP table and start recursion
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();  // Number of matrices (given as dimensions)
        dp.assign(n, vector<int>(n, -1)); // Initialize DP table with -1 (indicating uncomputed states)
        return helper(0, n - 1, arr);  // Start recursive computation from first to last matrix
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends