class Solution {
public:
    int getLongestPrefix(string &s) {
        int n = s.size();

        for (int len = n - 1; len >= 1; len--) {
            bool ok = true;

            // Check if remainder suffix matches prefix repeated (partial allowed)
            for (int i = len; i < n; ++i) {
                if (s[i] != s[(i - len) % len]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return len;
        }

        return -1;
    }
};
