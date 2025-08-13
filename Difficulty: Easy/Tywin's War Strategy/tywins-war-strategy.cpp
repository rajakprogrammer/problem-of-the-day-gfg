#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int need = (n + 1) / 2;  // ⌈n/2⌉ lucky troops required
        int lucky = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : arr) {
            if (num % k == 0) {
                lucky++;
            } else {
                pq.push(k - (num % k));
            }
        }

        if (lucky >= need) return 0;

        int total = 0;
        int required = need - lucky;

        for (int i = 0; i < required && !pq.empty(); ++i) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};
