//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n=s.size();
        int k=0;
        while(s[k]=='0')
        {
            ++k;
        }
        s=s.substr(k,n-k+1);
        n=s.size();
        if(s[n-1]=='0')
        {
            s[n-1]='1';
            return s;
        }
        int j=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                s[i]='0';
            }
            else
            {
                s[i]='1';
                return s;
            }
        }
       
        
        s='1'+s;
        return s;
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
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends