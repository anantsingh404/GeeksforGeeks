//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        double x=3.14*r*r;
        int i =1;
        int count=0;
        while(i<2*r)
        {    
        
            for(int j=1;j<=2*r;j++)
            {
               int  xy=pow(j,2)+pow(i,2);
               int z=ceil(sqrt(xy));
               if(z<=2*r)
               {
                   ++count;
               }
            }
            ++i;
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends