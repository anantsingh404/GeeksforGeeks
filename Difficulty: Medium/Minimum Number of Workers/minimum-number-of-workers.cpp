class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) continue;

            int l = max(0, i - arr[i]);
            int r = min(n - 1, i + arr[i]);
            intervals.push_back({l, r});
        }

        if (intervals.empty()) return -1;

        sort(intervals.begin(), intervals.end());

        int workers = 0;
        int currEnd = -1;
        int farthest = -1;
        int i = 0;

        while (currEnd < n - 1) {
            while (i < intervals.size() && intervals[i].first <= currEnd + 1) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }

            if (farthest == currEnd) {
                return -1; // cannot extend coverage
            }

            workers++;
            currEnd = farthest;
        }

        return workers;
    }
};
