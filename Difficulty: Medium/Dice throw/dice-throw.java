class Solution {
    static int solve(int idx,int n,int sum,int m,int x,int [][] dp)
    {
        if(idx>n && sum==x)
        {
            return 1;
        }
        if(idx>n)
        {
            return 0;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            ans+=solve(idx+1,n,sum+i,m,x,dp);
        }
        return dp[idx][sum]=ans;
        
    }
    static int noOfWays(int m, int n, int x) {
        // code here
        int [][] dp=new int[n+1][5001];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<5001;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(1,n,0,m,x,dp);
    }
};