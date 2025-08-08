class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);  // lps[i] = length of longest proper prefix which is also suffix for s[0..i]

        int len = 0; // length of previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // try shorter prefix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n - 1]; // longest prefix-suffix length for whole string
    }
};
