class Solution {
    public int countSquare(int[][] mat, int x) {
        // code here
        int n=mat.length;
        int m=mat[0].length;
        int [][] dp=new int [n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int j=0;j<m;j++)
        {
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++)
        {   
            for(int j=0;j<m;j++)
        {
            dp[i][j]=mat[i][j]+dp[i-1][j];
        }
        }
        for(int i=0;i<n;i++)
        {   
            for(int j=1;j<m;j++)
            {
            dp[i][j]+=dp[i][j-1];
            }
        }
        int ans=0;
         for(int i=0;i<n;i++)
        {   for(int j=0;j<m;j++)
        {
            int sum=0;
            for(int k=0;k+i<n && k+j<m;k++)
            {
                sum=dp[i+k][j+k];
                if(i-1>=0)
                {
                    sum-=(dp[i-1][j+k]);
                }
                if(j-1>=0)
                {
                    sum-=(dp[i+k][j-1]);
                }
                if(i-1>=0 && j-1>=0)
                {
                    sum+=dp[i-1][j-1];
                }
                if(sum==x)
                {
                    ++ans;
                }
            }
        }
        }
        return ans;
        
        
        
        
    }
}