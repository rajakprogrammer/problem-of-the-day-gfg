#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(string &s) {
        int n = (int)s.size();
        if (n == 0) return 0;

        // 1) Manacher (odd)
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k--;
            if (i + k > r) { l = i - k; r = i + k; }
        }

        // 2a) bestEnd[e]: longest odd palindrome ending at e
        vector<int> bestEnd(n, 0);
        struct NodeEnd { int i, end; };
        struct CmpMinI {
            bool operator()(const NodeEnd& a, const NodeEnd& b) const {
                return a.i > b.i; // min-heap by i
            }
        };
        priority_queue<NodeEnd, vector<NodeEnd>, CmpMinI> pqEnd;
        int ci = 0;
        for (int e = 0; e < n; ++e) {
            while (ci <= e && ci < n) {
                int reach = ci + d1[ci] - 1;
                pqEnd.push({ci, reach});
                ++ci;
            }
            while (!pqEnd.empty() && pqEnd.top().end < e) pqEnd.pop();
            if (!pqEnd.empty()) {
                int i = pqEnd.top().i;
                bestEnd[e] = 2 * (e - i) + 1;
            }
        }

        // 2b) bestStart[s]: longest odd palindrome starting at s
        vector<int> bestStart(n, 0);
        struct NodeStart { int i, start; };
        struct CmpMaxI {
            bool operator()(const NodeStart& a, const NodeStart& b) const {
                return a.i < b.i; // max-heap by i
            }
        };
        priority_queue<NodeStart, vector<NodeStart>, CmpMaxI> pqStart;
        int cj = n - 1;
        for (int sidx = n - 1; sidx >= 0; --sidx) {
            while (cj >= sidx) {
                int st = cj - d1[cj] + 1;
                pqStart.push({cj, st});
                --cj;
            }
            while (!pqStart.empty() && pqStart.top().start > sidx) pqStart.pop();
            if (!pqStart.empty()) {
                int i = pqStart.top().i;
                bestStart[sidx] = 2 * (i - sidx) + 1;
            }
        }

        // 3) prefix/suffix maxima
        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = bestEnd[0];
        for (int i = 1; i < n; ++i) pref[i] = max(pref[i - 1], bestEnd[i]);
        suff[n - 1] = bestStart[n - 1];
        for (int i = n - 2; i >= 0; --i) suff[i] = max(suff[i + 1], bestStart[i]);

        // 4) best split
        int ans = 0;
        for (int p = 0; p + 1 < n; ++p) {
            ans = max(ans, pref[p] + suff[p + 1]);
        }
        return ans;
    }
};
