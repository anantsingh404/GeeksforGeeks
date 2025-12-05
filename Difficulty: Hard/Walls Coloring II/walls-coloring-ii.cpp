class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n=costs.size();
        int m=costs[0].size();
        if(m==1 && n>1)
        {
            return -1;
        }
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int j=0;j<m;j++)
        {
            dp[0][j]=costs[0][j];
            pq.push(costs[0][j]);
        }
        for(int i=1;i<n;i++)
        {     
            for(int j=0;j<m;j++)
            {  int flag=0;
             if(pq.top()==dp[i-1][j])
             {
               flag=1;
               pq.pop();
             }
             dp[i][j]=min(pq.top()+costs[i][j],dp[i][j]);
             if(flag)
             {
                 pq.push(dp[i-1][j]);
             }
            }
            while(pq.size()>0)
            {pq.pop();
            }
            for(int j=0;j<m;j++)
            {
                pq.push(dp[i][j]);
            }
            
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};