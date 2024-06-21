//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sen) {

        // code here
        long long ans=-1;
        int i=0;
        while(i<sen.size())
        {   
            if(sen[i]>'0' && sen[i]<='9')
            {
               long long flag=0;
               bool c9=true;
               while(i<sen.size() &&sen[i]>='0' && sen[i]<='9')
               {   if(sen[i]=='9')
               {
                   c9=false;
               }
                   flag=flag*10+(sen[i]-'0');
                   i++;
               }
               if(c9){
               ans=max(ans,flag);
               }
            }
            else
            {
                i++;
            }
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
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends