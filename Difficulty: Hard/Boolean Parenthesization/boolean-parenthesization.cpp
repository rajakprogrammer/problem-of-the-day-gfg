//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;
    
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;

        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = solve(s, i, k - 1, true);
            int leftFalse = solve(s, i, k - 1, false);
            int rightTrue = solve(s, k + 1, j, true);
            int rightFalse = solve(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue)
                    ways += leftTrue * rightTrue;
                else
                    ways += leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse;
            } else if (s[k] == '|') {
                if (isTrue)
                    ways += leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
                else
                    ways += leftFalse * rightFalse;
            } else if (s[k] == '^') {
                if (isTrue)
                    ways += leftTrue * rightFalse + leftFalse * rightTrue;
                else
                    ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }

        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return solve(s, 0, s.length() - 1, true);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends