//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        vector<int>dp(d,0);
        if(s>9*d)
        {
            return "-1";
        }
        if(d==1)
        {
            if(s<=9)
            {
                return to_string(s);
            }
            return "-1";
        }
        dp[0]=1;
        --s;
        int i=d-1;
        while(i>=0)
        {   if(i==0 && s>0)
        {
            dp[i]=dp[i]+s;
            s=s-dp[i]+1;
        }else{
            dp[i]=min(9,s);
            s-=dp[i];
        }
            
            if(s==0)
            {
                break;
            }
            --i;
        }
        if(s)
        {
            return "-1";
        }
        string ans;
        for(int i=0;i<d;i++)
        {   string temp=to_string(dp[i]);
            ans+=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends