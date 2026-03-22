class pair{
    int x;
    int y;
    int time;
    pair(int x,int y,int time)
    {
        this.x=x;
        this.y=y;
        this.time=time;
    }
}
class Solution {
    public int orangesRot(int[][] mat) {
        // code here
        Queue<pair>q=new LinkedList<>();
        int n=mat.length;
        int m=mat[0].length;
         int [][]dp=new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    dp[i][j]=0;
                    q.add(new pair(i,j,0));
                }
                else
                {
                    dp[i][j]=Integer.MAX_VALUE;
                }
            }
        }
        int [] arr=new int[4];
        int [] brr=new int[4];
        arr[0]=0;
        arr[1]=0;
        arr[2]=-1;
        arr[3]=1;
        brr[0]=-1;
        brr[1]=1;
        brr[2]=0;
        brr[3]=0;
        while(q.size()>0)
        {
          pair p=q.peek();
          int x=p.x;
          int y=p.y;
          int time=p.time;
          q.poll();
          for(int i=0;i<4;i++)
          {
              int pp=x+arr[i];
              int qq=y+brr[i];
              if(pp>=0 && qq>=0 && pp<n && qq<m && mat[pp][qq]==1 && dp[pp][qq]>time+1)
              {
                  q.add(new pair(pp,qq,time+1));
                  dp[pp][qq]=time+1;
              }
          }
          
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==Integer.MAX_VALUE && mat[i][j]==1)
                {
                    return -1;
                }
                 if(dp[i][j]!=Integer.MAX_VALUE && mat[i][j]==1)
                {
                    maxi=Math.max(maxi,dp[i][j]);
                }
            }
        }
        return maxi;
        
        
        
    }
}