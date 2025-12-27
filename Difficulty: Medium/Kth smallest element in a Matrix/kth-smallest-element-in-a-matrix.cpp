class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
       int  m= mat[0].size();

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<>
    > pq;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pq.push({mat[0][0], {0, 0}});
    visited[0][0] = true;

    int ans = -1;

    while (k--)
    {
        auto cur = pq.top();
        pq.pop();

        int val = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;

        ans = val;

        if (x + 1 < n && !visited[x + 1][y])
        {
            pq.push({mat[x + 1][y], {x + 1, y}});
            visited[x + 1][y] = true;
        }

        if (y + 1 < m && !visited[x][y + 1])
        {
            pq.push({mat[x][y + 1], {x, y + 1}});
            visited[x][y + 1] = true;
        }
    }

    return ans;
    }
};
