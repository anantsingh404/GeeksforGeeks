class Solution {
    int n;
    int m;
    int solve(int i,int j1,int j2,int [][][]dp,int [][]grid )
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)
        {
            return Integer.MIN_VALUE;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int res=Integer.MIN_VALUE;
        for(int y=-1;y<=1;y++)
        {   
            for(int z=-1;z<=1;z++)
            {  int ans=0;
               if(j1==j2)
               {
                 ans=grid[i][j1]+solve(i+1,j1+y,j2+z,dp,grid);  
               }
               else
               {
                   ans=grid[i][j1]+grid[i][j2]+solve(i+1,j1+y,j2+z,dp,grid);  
               }
               res=Math.max(ans,res);
            }
            
            
        }
        return dp[i][j1][j2]=res;
        
    }
    public int maxChocolate(int grid[][]) {
        // code here
        n=grid.length;
        m=grid[0].length;
        int [][][]dp=new int[n][m][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(0,0,m-1,dp,grid);
    }
}