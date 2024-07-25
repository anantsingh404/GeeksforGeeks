//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string s, int k) {
        // code here
        vector<int>dp(26,0);
        int count=0;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                int x=s[i]-'a';
                if(dp[x]==0)
                {
                    dp[x]=1;
                    ++count;
                }
                ++sum;
            }
            if(count==26)
            {
                return true;
            }
        }
        if(26-count<=k && sum>=26)
        {
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends