//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms_needed = 1, max_platforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { 
                platforms_needed++;
                i++;
            } else { 
                platforms_needed--;
                j++;
            }
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends