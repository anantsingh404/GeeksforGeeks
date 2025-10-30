class Solution {
  public:
  int n,m;
  int arr[4]={-1,1,0,0};
  int brr[4]={0,0,-1,1};
   void solve(int i,int j,vector<vector<char>>&grid)
   {
       grid[i][j]='A';
       for(int k=0;k<4;k++)
       {
         int x=arr[k]+i;
         int y=j+brr[k];
         if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='O')
         {
             solve(x,y,grid);
         }
       }
   }
    void fill(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='O')
            {
                solve(i,0,grid);
            }
        }
         for(int j=0;j<m;j++)
        {
            if(grid[0][j]=='O')
            {
                solve(0,j,grid);
            }
        }
         for(int j=0;j<m;j++)
        {
            if(grid[n-1][j]=='O')
            {
                solve(n-1,j,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]=='O')
            {
                solve(i,m-1,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
                if(grid[i][j]=='A')
                {
                    grid[i][j]='O';
                }
            }
        }
    }
};