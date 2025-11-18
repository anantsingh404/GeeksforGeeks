class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        vector<int>com(n,0);
        com[0]=1;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            int cost=edges[i][2];
            adj[x].push_back({y,cost});
            adj[y].push_back({x,cost});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [x,y]=pq.top();
            pq.pop();
            for(auto itr :adj[y])
            {
                if(x+itr.second<dis[itr.first])
                {
                    dis[itr.first]=x+itr.second;
                    pq.push({dis[itr.first],itr.first});
                    com[itr.first]=com[y];
                }
                else if(x+itr.second==dis[itr.first])
                {
                     com[itr.first]=com[y]+com[itr.first]; 
                }
            }
        }return com[n-1];
        
        
    }
};