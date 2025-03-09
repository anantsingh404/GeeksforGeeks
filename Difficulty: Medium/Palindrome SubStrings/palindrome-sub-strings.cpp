//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans=0;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int left=i;
            int right=i+1;
            int count=0;
            while(left>=0 && right<n)
            {
              if(s[left]!=s[right])
              {
                  break;
              }
              else
              {   ++ans;
                  --left;
                  ++right;
                  count+=2;
                  //ans=max(ans,count);
              }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int left=i-1;
            int right=i+1;
            int count=1;
            while(left>=0 && right<n)
            {
              if(s[left]!=s[right])
              {
                  break;
              }
              else
              {  ++ans;
                  --left;
                  ++right;
                  count+=2;
                 // ans=max(ans,count);
              }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends