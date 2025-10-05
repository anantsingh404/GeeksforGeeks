class Solution {
  public:
  int n,m;
  int arr[4]={-1,1,0,0};
  int brr[4]={0,0,-1,1};
  void solve(int i,int j,string &res,vector<vector<int>>&vis,vector<string>&ans,vector<vector<int>>& maze){
      if(i==n-1 && j==m-1){
          ans.push_back(res);
          return ;
      }
      for(int idx=0;idx<4;idx++)
      {
          int x=i+arr[idx];
          int y=j+brr[idx];
          if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && maze[x][y]==1){
              if(idx==0)
              {
                  res.push_back('U');
              }
              else if(idx==1)
              {
                  res.push_back('D');
              }
              else if(idx==2)
              {
                  res.push_back('L');
              }
              else if(idx==3)
              {
                  res.push_back('R');
              }
              vis[x][y]=1;
              solve(x,y,res,vis,ans,maze);
              vis[x][y]=0;
              res.pop_back();
          }
      }
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n=maze.size();
        m=maze[0].size();
        vector<string>ans;
        if(maze[0][0]==0)
        {
            return ans;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        string res="";
        vis[0][0]=1;
        solve(0,0,res,vis,ans,maze);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};