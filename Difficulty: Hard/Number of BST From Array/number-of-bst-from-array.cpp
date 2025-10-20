class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
         int n = arr.size();
    vector<pair<int,int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {arr[i], i};
    }
    sort(vp.begin(), vp.end());  // sort by value (if duplicates, by index)

    // Precompute C[0..n], where C[k] = number of BSTs with k distinct nodes
    vector<long long> C(n+1, 0);
    C[0] = 1;
    for (int k = 1; k <= n; k++) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += C[i] * C[k-1-i];
        }
        C[k] = sum;
    }

    vector<int> res(n, 0);
    for (int sortedPos = 0; sortedPos < n; sortedPos++) {
        int origIndex = vp[sortedPos].second;
        // left has sortedPos nodes, right has (n-1-sortedPos) nodes
        res[origIndex] = C[sortedPos] * C[n-1-sortedPos];
    }
    return res;
    }
};