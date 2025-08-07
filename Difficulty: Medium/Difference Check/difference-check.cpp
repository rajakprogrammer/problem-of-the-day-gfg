class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> times;

        // Convert to total seconds since midnight
        for (string &time : arr) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            int s = stoi(time.substr(6, 2));
            int total = h * 3600 + m * 60 + s;
            times.push_back(total);
        }

        sort(times.begin(), times.end());

        int minDiff = INT_MAX;

        // Compare adjacent times
        for (int i = 1; i < times.size(); ++i) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }

        // Handle midnight wrap-around
        int daySeconds = 24 * 3600;
        int circularDiff = daySeconds - times.back() + times[0];
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
