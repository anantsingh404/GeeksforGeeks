class Solution {
  public:
  const int mod=1e9+7;
    int distinctSubseq(string &s) {
        // code here
        int n=s.size();
	    unordered_map<char,int>mp;
	    vector<long long int>dp(n+1,0);
	    dp[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=2*(dp[i-1]%mod);
	        if(mp.find(s[i-1])!=mp.end())
	        {
	            dp[i]=(dp[i]%mod-(dp[mp[s[i-1]]-1])%mod+mod)%mod;
	        }
	        mp[s[i-1]]=i;
	    }
	    return dp[n]%mod;
    }
};