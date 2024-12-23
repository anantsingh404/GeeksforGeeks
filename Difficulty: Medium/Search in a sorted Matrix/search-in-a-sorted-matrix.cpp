//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int mini=0;
        int maxi=mat.size()-1;
        int ans=-1;
        int m=mat[0].size();
        while(mini<=maxi)
        {   
            int mid=(maxi+mini)/2;
            if(mat[mid][m-1]<x)
            {   
                mini=mid+1;
                
            }
            else if(mat[mid][0]>x)
            {
                maxi=mid-1;
            }
            else if(x>=mat[mid][0] && x<=mat[mid][m-1])
            {
                ans=mid;
                break;
                
            }
        }
        if(ans==-1)
        {
            return false;
        }
        mini=0;
        maxi=m-1;
         while(mini<=maxi)
        {
            int mid=(maxi+mini)/2;
            if(mat[ans][mid]<x)
            {
                mini=mid+1;
            }
            else if(mat[ans][mid]>x)
            {
                maxi=mid-1;
            }
            else
            {
                return true;
                
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends