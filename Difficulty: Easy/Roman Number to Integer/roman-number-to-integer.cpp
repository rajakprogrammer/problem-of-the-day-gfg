class Solution {
  public:
    int romanToDecimal(string &s) {
        // Create a map to store Roman numeral values
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;  // To store the final result
        int n = s.length();

        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            int curr = romanMap[s[i]];  // Current Roman value
            int next = (i + 1 < n) ? romanMap[s[i + 1]] : 0;  // Next Roman value (if exists)

            // If current is less than next, subtract (e.g., IV = 4)
            if (curr < next) {
                total -= curr;
            } else {
                total += curr;
            }
        }

        return total;  // Return the computed integer value
    }
};
