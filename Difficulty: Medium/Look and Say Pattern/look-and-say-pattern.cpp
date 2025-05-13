//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string ans="1";
        if(n==1)
        {
            return "1";
        }
        
        for(int i=2;i<=n;i++)
        {
            int m=ans.size();
            string x;
            int j=0;
            int k=0;
            int count=0;
            while(j<m)
            {
                if(ans[j]==ans[k])
                {
                    ++count;
                    ++j;
                }
                else
                {
                    string y=to_string(count);
                    x+=y;
                    x.push_back(ans[k]);
                    count=0;
                    k=j;
                    
                }
                
            }
              string y=to_string(count);
                    x+=y;
                    x.push_back(ans[m-1]);
            ans=x;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends