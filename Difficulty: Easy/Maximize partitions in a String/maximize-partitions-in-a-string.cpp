//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size(), partitions = 0, maxIndex = 0;

        // Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        // Traverse string and decide partitions
        for (int i = 0; i < n; i++) {
            maxIndex = max(maxIndex, lastIndex[s[i]]);
            if (i == maxIndex) {
                partitions++;
            }
        }
        return partitions;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends