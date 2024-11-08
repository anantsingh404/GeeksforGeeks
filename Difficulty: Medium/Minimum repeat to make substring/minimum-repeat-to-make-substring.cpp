//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        string flag=a;
        int count=1;
        while(flag.size()<b.size())
        {
            flag=flag+a;
            ++count;
        }
        for(int i=0;i<=flag.size()-b.size();i++)
        {
            if(flag.substr(i,b.size())==b)
            {
               return count; 
            }
        }
        flag=flag+a;
        for(int i=0;i<flag.size()-b.size();i++)
        {
            if(flag.substr(i,b.size())==b)
            {
                return count+1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends