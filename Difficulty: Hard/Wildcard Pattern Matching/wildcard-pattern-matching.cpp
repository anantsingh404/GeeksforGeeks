//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
bool xyz(string &s,int i)
{
    for(int j=0;j<=i;j++)
    {
        if(s[j]!='*')
        {
            return false;
        }
    }
    return true;
}
int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if (i < 0 && j >= 0)
        {
        return xyz(t, j);
        }
        if (dp[i][j] != -1)
        return dp[i][j];
        if (s[i] == t[j] || t[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1,s,t,dp);
    else {
        if (t[j] == '*')
            
            return dp[i][j] = solve(i , j-1,s,t, dp) || solve(i-1, j,s,t, dp);
        else
            return false;
    }
    }
    int wildCard(string p,string s)
    {
         int n=s.size();
       int m=p.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,s,p,dp); 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends