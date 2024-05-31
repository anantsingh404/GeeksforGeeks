//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int count=0;
        vector<int>dp(26,0);
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if((i+1)%2==0)
            {
                if(dp[i]%2==0 && dp[i]!=0)
                {
                    ++count;
                }
            }
            else
            {
                if(dp[i]%2==1 && dp[i]!=0)
                {
                    ++count;
                }
            }
        }
        if(count%2==0)
        {
            return "EVEN";
        }
        return "ODD";
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends