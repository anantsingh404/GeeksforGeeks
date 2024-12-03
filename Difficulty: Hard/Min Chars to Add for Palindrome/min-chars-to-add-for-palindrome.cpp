//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:    int minChar(string& s) {
        // Write your code here
        int n=s.length();

        string rev(s);

        reverse(rev.begin(),rev.end());

        string new_str=s+"#"+rev;

        int new_len=new_str.length();

        vector<int> tmp(new_len+1,0);

        for(int i=1;i<new_len;i++){

            int t=tmp[i-1];

            while(t>0 && new_str[i]!=new_str[t])t=tmp[t-1];

            if(new_str[i]==new_str[t])++t;

            tmp[i]=t;

        }

        return n-tmp[new_len-1];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends