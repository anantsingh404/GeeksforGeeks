//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double powerr(double b,int x)
    {
        if(x==0)
        {
            return 1;
        }
        double p=powerr(b,x/2);
        if(x%2)
        {
            return b*p*p;
        }
        return p*p;
    }
    double power(double b, int e) {
        // code here
      
        int x=abs(e);
        double ans=powerr(b,x); 
        if(e<0)
        {
            return 1/ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends