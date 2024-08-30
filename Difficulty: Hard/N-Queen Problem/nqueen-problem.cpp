//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>>ans;
bool check(vector<vector<int>>&dp,int i,int k)
{
    //dp[i][k]=0;
    bool ans=true;
    int x=i;
    while(x>=0)
    {
      if(dp[x][k]==1)
      {
          ans=false;
          break;
      }
      x--;
    }
    int p=i;
    int q=k;
    while(p>=0 && q>=0 )
    {
        if(dp[p][q]==1)
        {
            ans=false;
        }
        --p;
        --q;
    }
    int l=i;
    int m=k;
    while(m<dp.size() && l>=0 )
    {
        if(dp[l][m]==1)
        {
            ans=false;
        }
        --l;
        ++m;
    }
   // dp[i][k]=1;
    return ans;
}


void solve(int i,vector<vector<int>>&dp,vector<int>&temp,int n)
{
    for(int k=0;k<dp.size();k++)
    {
        if(check(dp,i,k))
        {
            temp.push_back(k+1);
            dp[i][k]=1;
            if(n>1)
            {
            solve(i+1,dp,temp,n-1);
            temp.pop_back();
            }
            else
            {
                ans.push_back(temp);
                temp.pop_back();
            }
            dp[i][k]=0;
        }
    }
    return ;
}

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>temp;
        solve(0,dp,temp,n);
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends