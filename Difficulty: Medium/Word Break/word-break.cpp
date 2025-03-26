//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreak(string &A, vector<string> &B) {
        // code here
        int n=A.length();
        unordered_map<string,int>ans;
        for(int i=0;i<B.size();i++)
        {
           ans[B[i]]++;
        }
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {   if(i-j<=100){
                if(dp[j]==true && ans[A.substr(j,i-j)]>=1)
                {
                    dp[i]=true;
                    //cout<<i<<" "<<dp[i]<<endl;
                }
            }
            }
        }
        if(dp[n]==true)
        {
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends