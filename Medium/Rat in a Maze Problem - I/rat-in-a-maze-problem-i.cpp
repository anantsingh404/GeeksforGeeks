//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>> &m,vector<string>&ans,string x)
    {
        if(i>=n || i<0 || j>=n || j<0 || m[i][j]==0)
        {
            return ;
        }
        if(i==n-1 && j==n-1 && m[i][j]==1)
        {
            ans.push_back(x);
            return;
        }
       
        m[i][j]=0;
        solve(i+1,j,n,m,ans,x+"D");
        solve(i,j+1,n,m,ans,x+"R");
        solve(i-1,j,n,m,ans,x+"U");
        solve(i,j-1,n,m,ans,x+"L");
        m[i][j]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string x="";
        solve(0,0,n,m,ans,x);
        sort(ans.begin(),ans.end());
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends