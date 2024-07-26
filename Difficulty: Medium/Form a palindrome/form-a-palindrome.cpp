//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  vector<vector<int>>dp;
  int solve(int i,int j,string &str)
  {
      if(i>j)
      {
          return 0;
      }
      if(i==j)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      int ans=0;
      if(str[i]==str[j])
      {
          ans=solve(i+1,j-1,str);
      }
      else
      {
          ans=min(1+solve(i+1,j,str),1+solve(i,j-1,str));
      }
      return dp[i][j]=ans;
  }
    int countMin(string str){
    //complete the function here

    int n=str.size();
    int i=0;
    int j=n-1;
    dp.assign(n,vector<int>(n,-1));
    return solve(i,j,str);
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends