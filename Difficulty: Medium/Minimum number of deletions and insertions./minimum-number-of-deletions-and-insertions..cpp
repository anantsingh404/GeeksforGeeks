//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int n,m;
	int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
	{
	    if(j==m)
	    {
	        return abs(n-i);
	    }
	    if(i==n)
	    {
	        if(j==m)
	        {
	            return 0;
	        }
	        if(j<m)
	        {
	            return abs(m-j);
	        }
	        
	    }
	    
	    if(dp[i][j]!=-1)
	    {
	        return dp[i][j];
	    }
	    int ans=1e9;
	    if(s1[i]==s2[j])
	    {
	      ans=min(ans,solve(i+1,j+1,s1,s2,dp));
	     
	    }
	    ans=min(ans,1+solve(i+1,j,s1,s2,dp));
	     ans=min(ans,1+solve(i,j+1,s1,s2,dp));
	     return dp[i][j]=ans;
	    
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    n=str1.size();
	    m=str2.size();
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    return solve(0,0,str1,str2,dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends