#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int far;
    int farNode;

    void dfs(int idx, vector<vector<int>> &adj, vector<int> &vis, int depth)
    {
        vis[idx] = 1;

        if(depth > far)
        {
            far = depth;
            farNode = idx;
        }

        int i = 0;
        while(i < adj[idx].size())
        {
            int x = adj[idx][i];

            if(vis[x] == 0)
            {
                dfs(x, adj, vis, depth + 1);
            }

            i++;
        }
    }

    bool getPath(int idx, int target, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
    {
        vis[idx] = 1;
        path.push_back(idx);

        if(idx == target)
        {
            return true;
        }

        int i = 0;
        while(i < adj[idx].size())
        {
            int x = adj[idx][i];

            if(vis[x] == 0)
            {
                bool res = getPath(x, target, adj, vis, path);
                if(res)
                {
                    return true;
                }
            }

            i++;
        }

        path.pop_back();
        return false;
    }

    vector<int> minHeightRoot(int n, vector<vector<int>> &e)
    {
        vector<vector<int>> adj;
        vector<int> vis;
        vector<int> path;
        vector<int> ans;

        int i;

        adj.resize(n);
        i = 0;
        while(i < e.size())
        {
            int u = e[i][0];
            int v = e[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            i++;
        }

        vis.assign(n, 0);

        // 1st DFS
        far = -1;
        dfs(0, adj, vis, 0);
        int node1 = farNode;

        // reset vis
        vis.assign(n, 0);

        // 2nd DFS
        far = -1;
        dfs(node1, adj, vis, 0);
        int node2 = farNode;

        // reset vis again
        vis.assign(n, 0);

        // get path
        getPath(node1, node2, adj, vis, path);

        int len = path.size();

        if(len % 2 == 1)
        {
            ans.push_back(path[len / 2]);
        }
        else
        {
            ans.push_back(path[len / 2 - 1]);
            ans.push_back(path[len / 2]);
        }

        return ans;
    }
};