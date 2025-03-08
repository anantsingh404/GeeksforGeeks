//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool check(int i,int j,string &s)
  {
      while(i<j)
      {
          if(s[i]!=s[j])
          {
              return false;
          }
          i++;
          j--;
      }
      return true;
  }
    string longestPalindrome(string &s) {
        // code here
        int left=-1;
        int right=-1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(i,j,s))
                {
                    if(right-left+1<j-i+1)
                    {
                        left=i;
                        right=j;
                    }
                }
            }
        }
        return s.substr(left,right-left+1);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends