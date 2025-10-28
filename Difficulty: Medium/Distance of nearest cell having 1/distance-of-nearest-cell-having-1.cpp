class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int  m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int arr[8]={-1,-1,-1,0,0,1,1,1};
        int brr[8]={-1,1,0,-1,1,-1,1,0};
        while(!q.empty())
        {
          pair<int,int>p=q.front();
          q.pop();
          int x=p.first;
          int y=p.second;
          for(int i=0;i<8;i++){
              int l=x+arr[i];
              int c=y+brr[i];
              if(l>=0 && c>=0 && l< n && c<m && grid[l][c]==0 && dp[x][y]+abs(x-l)+abs(y-c)<dp[l][c])
              {
                  dp[l][c]=dp[x][y]+abs(x-l)+abs(y-c);
                  q.push({l,c});
              }
          }
        }
        return dp;
        
    }
};