class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();int m=mat[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        pq.push({0,{0,0}});
        int arr[4]={-1,1,0,0};
        int brr[4]={0,0,-1,1};
        while(!pq.empty())
        {
          auto p=pq.top();
          int px=p.second.first;
          int py=p.second.second;
          int pc=p.first;
          pq.pop();
          for(int i=0;i<4;i++)
          {
              int x=arr[i]+p.second.first;
              int y=brr[i]+p.second.second;
              if(x>=0 && y>=0 && x<n && y<m && dp[x][y]>max(pc,abs(mat[px][py]-mat[x][y])))
              {
                  dp[x][y]=max(pc,abs(mat[px][py]-mat[x][y]));
                  pq.push({dp[x][y],{x,y}});
              }
          }
        }
        return dp[n-1][m-1];
    }
};
