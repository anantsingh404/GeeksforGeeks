class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        vector<int>times;
        for (string &s : arr) {
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3, 2));
        int ss = stoi(s.substr(6, 2));
        int totalSeconds = hh * 3600 + mm * 60 + ss;
        times.push_back(totalSeconds);
    }
    int n=arr.size();
    sort(times.begin(), times.end());
    int minDiff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        minDiff = min(minDiff, times[i] - times[i - 1]);
    }

    // Wrap-around case
    int lastToFirst = (times[0] + 86400) - times[n - 1]; // 86400 seconds in a day
    minDiff = min(minDiff, lastToFirst);

    return minDiff;
    }
};
