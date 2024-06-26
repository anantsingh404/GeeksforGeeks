//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int n=mat.size();
    int m=mat[0].size();
    bool flag=true;
    for(int j=0;j<m;j++)
    {
        int x=j;
        int y=0;
        ++x;
        ++y;
        while(y<n && x<m)
        {
            if(mat[y][x]!=mat[y-1][x-1])
            {
                flag=false;
            }
            ++y;
            ++x;
        }
        
    }
    for(int i=0;i<n;i++)
    {
        int x=i;
        int y=0;
        ++x;
        ++y;
        while(x<n && y<m)
        {
            if(mat[x][y]!=mat[x-1][y-1])
            {
                flag=false;
            }
            ++x;
            ++y;
        }
    }
    return flag;
}