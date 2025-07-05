class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
           sort(a.rbegin(), a.rend());  // Descending order
    sort(b.rbegin(), b.rend());
    int n = a.size(), m = b.size();

    priority_queue<tuple<int, int, int>> pq;
    set<pair<int, int>> visited;

    pq.emplace(a[0] + b[0], 0, 0);
    visited.insert({0, 0});

    vector<int> ans;

    while (!pq.empty() && ans.size() < k) {
        auto top = pq.top(); pq.pop();
        int sum = get<0>(top);
        int i = get<1>(top);
        int j = get<2>(top);

        ans.push_back(sum);

        if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
            pq.emplace(a[i + 1] + b[j], i + 1, j);
            visited.insert({i + 1, j});
        }

        if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
            pq.emplace(a[i] + b[j + 1], i, j + 1);
            visited.insert({i, j + 1});
        }
    }
        return ans;
    }
};