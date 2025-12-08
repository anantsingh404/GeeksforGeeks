class Solution {
  public:
   
        // code here
      pair<string,int> solve(int i,int j,vector<int>&p,vector<vector<pair<string,int>>>&dp)
{
    if(i==j)
    {   string st="";
        st+='A'+i-1;
        return {st,0};
    }
    if(dp[i][j].second!=-1)
    {
            return dp[i][j];
    }
        int ans=INT_MAX;
        string anss="";
        for(int k=i;k<=j-1;k++)
        {
            pair<string,int>x=solve(i,k,p,dp);
            pair<string,int>y=solve(k+1,j,p,dp);
            int m=x.second+y.second+p[i-1]*p[k]*p[j];
            if(m<ans)
            {
                ans=m;
                anss="("+x.first+y.first+")";
            }
        }
        return dp[i][j]={anss,ans};
    
}  
     string matrixChainOrder(vector<int> &p) {
         int n=p.size();
          vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n,{" " ,-1}));
        auto prr=solve(1,n-1,p,dp);
        return prr.first;
     }
};