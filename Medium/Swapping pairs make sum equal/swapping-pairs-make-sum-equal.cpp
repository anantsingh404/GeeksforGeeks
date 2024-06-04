//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        int sum1=0;
        int sum2=0;
        sum1=accumulate(a,a+n,0);
        sum2=accumulate(b,b+m,0);
        int x=abs(sum1-sum2);
        if(x==0)
        {
            return 1;
        }
        if(x%2)
        {
            return -1;
        }
        x=x/2;
        if(sum1<sum2)
        {
            for(int i=0;i<m;i++)
            {
                if(binary_search(a,a+n,b[i]-x))
                {
                    return 1;
                }
            }
        }
        if(sum1>sum2)
        {
            for(int i=0;i<m;i++)
            {
                if(binary_search(a,a+n,b[i]+x))
                {
                    return 1;
                }
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends