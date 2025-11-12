class Solution {
  public:
  int n,m;
    int solve(int i,int j,string &txt,string &pat,vector<vector<int>>&dp)
    {
        if(i>=n && j>=m){
            return 1;
        }
        if(j==m)
        {
            return 0;
        }
        if(i==n)
        {
            bool temp=false;
            for(int k=j;k<m;k++)
            {
                if(pat[k]!='*')
                {
                    temp=true;
                    break;
                }
            }
            if(temp)
            {
                return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(txt[i]==pat[j] || pat[j]=='?')
        {
            ans=solve(i+1,j+1,txt,pat,dp);
        }
        if(pat[j]=='*')
    {
       ans|=solve(i+1,j,txt,pat,dp);
       ans|=solve(i,j+1,txt,pat,dp);
    }
        return dp[i][j]=ans;
    }
    bool wildCard(string &txt, string &pat) {
        // code here
        n=txt.size();
        m=pat.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,txt,pat,dp);
    }
};