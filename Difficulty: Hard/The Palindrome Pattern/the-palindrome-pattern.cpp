//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        int m=arr[0].size();
        int ans=INT_MAX;
        char x;
        
        for(int i=0;i<n;i++)
        {
            vector<int>dp;
            dp=arr[i];
            reverse(dp.begin(),dp.end());
            if(dp==arr[i])
            {
                if(ans==INT_MAX)
                {
                    ans=i;
                    x='R';
                }
            }
            
            
        }
        for(int i=0;i<m;i++)
        {
            vector<int>dp;
            vector<int>dp1;
            for(int j=0;j<n;j++)
            {
                dp.push_back(arr[j][i]);
                dp1.push_back(arr[j][i]);
            }
            
            reverse(dp.begin(),dp.end());
            if(dp==dp1)
            {
                if(ans==INT_MAX)
                {
                    ans=i;
                    x='C';
                }
            }
            
           
        }
        if(ans==INT_MAX)
        {
            return "-1";
        }
        
        return to_string(ans)+' '+x;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends