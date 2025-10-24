class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
            unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp; // min-heap by length

        for (int val : arr) {
            if (!mp[val - 1].empty()) {
                // Extend shortest chain ending with val-1
                int len = mp[val - 1].top();
                mp[val - 1].pop();

                mp[val].push(len + 1); // increase length by 1
            } 
            else {
                // Start new chain of length 1
                mp[val].push(1);
            }
        }

        // Check if all chains have length >= k
        for (auto &p : mp) {
            auto pq = p.second;
            while (!pq.empty()) {
                if (pq.top() < k) return false;
                pq.pop();
            }
        }

        return true;
    }
};
