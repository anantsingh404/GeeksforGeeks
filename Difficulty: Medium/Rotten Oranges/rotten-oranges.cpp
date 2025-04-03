//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int arr[4]={-1,1,0,0};
  int brr[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
         vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2 )
                {
                    q.push({i,j});
                    dis[i][j]=0;
                   
                    
                }
                if(mat[i][j]==0)
                {
                     dis[i][j]=0; 
                }
                if(mat[i][j]==1)
                {
                     ++count;
                }
            }
        }
        if(q.empty() && count>0)
        {
            return -1;
        }
        if(q.empty())
        {
            return 0;
        }
       
        
        while(!q.empty())
        {
           auto x=q.front();
           int a=x.first;
           int b=x.second;
           q.pop();
           
           for(int i=0;i<4;i++)
           {
               int p=a+arr[i];
               int qq=b+brr[i];
               if(p>=0 && p<n && qq>=0 && qq<m && dis[p][qq]> dis[a][b]+1 && mat[p][qq]!=0)
               {
                   q.push({p,qq});
                   dis[p][qq]=dis[a][b]+1;
               }
               
           }
           
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               maxi=max(maxi,dis[i][j]);
            }
        }
        if(maxi==INT_MAX)
        {
            return -1;
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends