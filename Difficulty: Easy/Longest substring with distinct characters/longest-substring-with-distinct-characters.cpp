//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int i= 0;
        int j=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(i<s.size())
        {
            mp[s[i]]++;
            while(j<i && mp[s[i]]>1)
            {
                --mp[s[j]];
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends