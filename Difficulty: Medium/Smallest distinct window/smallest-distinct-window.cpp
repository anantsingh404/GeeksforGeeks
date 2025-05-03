//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>st(str.begin(),str.end());
        int m=st.size();
        int n=str.size();
        unordered_map<char,int>mp;
        st.clear();
        int i=0;
        int j=0;
        int ans=n;
        while(i<n)
        {
            mp[str[i]]++;
            st.insert(str[i]);
            while(j<i &&  st.size()==m && mp[str[j]]>1)
            {
                --mp[str[j]];
                ans=min(ans,i-j);
               
                if(mp[str[j]]==0)
                {
                    st.erase(str[j]);
                }
                 j++;
            }
            if(st.size()==m)
            {
                ans=min(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends