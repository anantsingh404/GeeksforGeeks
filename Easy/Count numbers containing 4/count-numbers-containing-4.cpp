//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(int n)
  {
      string x=to_string(n);
      for(int i=0;i<x.size();i++)
      {
         if(x[i]=='4')
         {
             return true;
         }
      }
      return false;
  }
    int countNumberswith4(int n) {
        // code here
        int count=0;
        for(int i=4;i<=n;i++)
        {
            if(solve(i))
            {
                ++count;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends