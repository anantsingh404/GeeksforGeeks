class Solution {
  public:
    int n;
vector<int> ans;
vector<vector<int>> dp;

int solve(int i, int j, vector<int>& arr) {
    if (i >= j) return 1;  // empty subtree = 1 way
    if (dp[i][j] != -1) return dp[i][j];

    int total = 0;
    for (int p = i; p <= j; p++) {
        int left = solve(i, p - 1, arr);
        int right = solve(p + 1, j, arr);
        int ways = left * right;
        total += ways;
         // count how many trees have root at arr[p]
    }
    return dp[i][j] = total;
}

vector<int> countBSTs(vector<int> arr) {
    n = arr.size();
    ans.assign(n, 0);
    dp.assign(n, vector<int>(n, -1));

    // Sort to follow BST property
    vector<pair<int,int>> vp;
    for (int i = 0; i < n; i++) vp.push_back({arr[i], i});
    sort(vp.begin(), vp.end());

    vector<int> sorted;
    for (auto &x : vp) sorted.push_back(x.first);
   for(int i=0;i<n;i++)
   {
        ans[i]=solve(0, i - 1, sorted)*solve(i+1,n-1,sorted);
   }
   

    // Map back to original indices
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int originalIndex = vp[i].second;
        res[originalIndex] = ans[i];
    }

    return res;
}
};