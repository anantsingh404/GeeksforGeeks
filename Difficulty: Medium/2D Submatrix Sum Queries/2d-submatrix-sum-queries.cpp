class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &q) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=dp[i-1][j]+mat[i][j];
            }
        }
        vector<int>res;
        for(auto itr:q)
        {
            int x1=itr[0];
            int y1=itr[1];
            int x2=itr[2];
            int y2=itr[3];
            int ans=0;
            ans+=dp[x2][y2];
            if(x1>0)
            {
                ans-=dp[x1-1][y2];
            }
            if(y1>0)
            {
                ans-=dp[x2][y1-1];
            }
            if(x1-1>=0 && y1-1>=0)
            {
              ans+=dp[x1-1][y1-1];  
            }
            res.push_back(ans);
            
            
        }
        return res;
    }
};
