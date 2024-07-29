//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int arr[4]={-1,1,0,0};
  int brr[4]={0,0,-1,1};
 
  vector<string>ans;
  int n;
  void solve(int i,int j,vector<vector<int>>&mat,string &temp)
  {  
       if(i==n-1 && j==n-1)
       {
           ans.push_back(temp);
           return;
       }
      mat[i][j]=0;
      for(int x=0;x<4;x++)
      {
          int p=i+arr[x];
          int q=j+brr[x];
          if(p>=0 && q>=0 && p<n &&q<n && mat[p][q]==1)
          {
              if(x==0)
              {
                  temp.push_back('U');
              }
              if(x==1)
              {
                  temp.push_back('D');
              }
              if(x==2)
              {
                  temp.push_back('L');
              }
              if(x==3)
              {
                  temp.push_back('R');
              }
              solve(p,q,mat,temp);
              temp.pop_back();
          }
      }
      mat[i][j]=1;
      
      return;
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        n=mat.size();
        
        if(mat[0][0]==0)
        {
            return {"-1"};
        }
        string temp="";
        
        solve(0,0,mat,temp);
        if(ans.empty())
        {
            return {"-1"};
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends