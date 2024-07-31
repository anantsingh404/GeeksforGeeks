//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int i=0;
        int j=0;
        --n;
        --m;
        vector<int>ans;
        while(i<=n && j<=m )
        {
           for(int k=j;k<=m;k++)
           {
               ans.push_back(mat[i][k]);
           }
           ++i;
           for(int k=i;k<=n;k++)
           {
               ans.push_back(mat[k][m]);
           }
           --m;
           if(i<=n){
           for(int k=m;k>=j;k--)
           {
               ans.push_back(mat[n][k]);
           }
           }
           --n;
           if(j<=m){
           for(int k=n;k>=i;k--)
           {
               ans.push_back(mat[k][j]);
           }
           }
           ++j;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends