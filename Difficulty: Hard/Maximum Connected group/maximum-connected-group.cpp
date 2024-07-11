//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
  int n;
  int arr[4]={-1,1,0,0};
int brr[4]={0,0,-1,1};
  int solve(int i,int j,vector<vector<int>>&grid,int k)
  {
      
      grid[i][j]=k;
      int count=0;
      for(int l=0;l<4;l++)
      {
          int x=i+arr[l];
          int y=j+brr[l];
          if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1)
          {
            count+=solve(x,y,grid,k);  
          }
      }
      return count+1;
  }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        int k=2;
      // vector<vector<int>>dp=grid;
       unordered_map<int,int>mp;
       mp[0]=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                if(grid[i][j]==1)
                {
                   int x=solve(i,j,grid,k);
                  // cout<<x<<endl;
                   ans=max(ans,x);
                   mp[k]=x;
                   ++k;
                }
            }
        }
     
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                if(grid[i][j]==0)
                {  /*
                   int x=i-1;
                   int y=i+1;
                   if(x>=0 && grid[x][j]!=0)
                   {
                       ans=max(ans,mp[grid[x][j]]+1);
                   }
                   if(y<n &&grid[y][j]!=0)
                   {
                       ans=max(ans,mp[grid[y][j]]+1); 
                   }
                   if(x>=0 && y<n && grid[x][j]!=grid[y][j] && grid[x][j]!=0 && grid[y][j]!=0)
                   {
                       ans=max(ans,mp[grid[x][j]]+mp[grid[y][j]]+1);
                   }
                   x=j-1;
                   y=j+1;
                   if(x>=0 && grid[i][x]!=0)
                   {
                     ans=max(ans,mp[grid[i][x]]+1);  
                   }
                   if(y<n && grid[i][y]!=0)
                   {
                     ans=max(ans,mp[grid[i][y]]+1);  
                   }
                   if(x>=0 && y<n && grid[i][x]!=grid[i][y])
                   {
                       ans=max(ans,mp[grid[i][x]]+mp[grid[i][y]]+1);
                   }
                   x=i-1;
                   y=j-1;
                   if(x>=0 && y>=0 && grid[x][j]!=grid[i][y])
                   {
                       ans=max(ans,mp[grid[x][j]]+mp[grid[i][y]]+1);
                   }
                    x=i-1;
                   y=j+1;
                   if(x>=0 && y<n && grid[x][j]!=grid[i][y])
                   {
                       ans=max(ans,mp[grid[x][j]]+mp[grid[i][y]]+1);
                   }
                    x=i+1;
                   y=j-1;
                   if(x<n && y>=0 && grid[x][j]!=grid[i][y])
                   {
                       ans=max(ans,mp[grid[x][j]]+mp[grid[i][y]]+1);
                   }
                    x=i+1;
                   y=j+1;
                   if(x<n && y<n && grid[x][j]!=grid[i][y])
                   {
                       ans=max(ans,mp[grid[x][j]]+mp[grid[i][y]]+1);
                   }
                   */
                   set<int>st;
                   int count=1;
                   //cout<<mp[2]<<endl;
                   for(int l=0;l<4;l++)
                   {
                       int x=arr[l]+i;
                       int y=brr[l]+j;
                       if(x>=0 && y>=0 && x<n && y<n)
                       {
                           if(st.find(grid[x][y])==st.end())
                           {
                               count+=mp[grid[x][y]];
                               st.insert(grid[x][y]);
                           }
                       }
                   }
                   //cout<<count<<endl;
                   ans=max(ans,count);
                   
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends