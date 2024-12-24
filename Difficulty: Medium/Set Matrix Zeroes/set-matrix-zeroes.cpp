//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int flagx=0;
        int flagy=0;
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]==0)
            {
                flagx=1;
            }
        }
         for(int i=0;i<n;i++)
        {
            if(mat[i][0]==0)
            {
                flagy=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(mat[i][0]==0)
            {
                int j=1;
                while(j<m)
                {
                    mat[i][j]=0;
                    j++;
                }
            }
        }
         for(int j=1;j<m;j++)
        {
            if(mat[0][j]==0)
            {
                int i=1;
                while(i<n)
                {
                    mat[i][j]=0;
                    i++;
                }
            }
        }
        if(flagx)
        {
            for(int j=0;j<m;j++)
            {
                mat[0][j]=0;
            }
        }
         if(flagy)
        {
            for(int i=0;i<n;i++)
            {
                mat[i][0]=0;
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends