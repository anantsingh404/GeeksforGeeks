//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string s) {
        // code here
        int n=s.size();
        int temp=0;
        int count=0;
        for(int i=0;i<n;i++)
        {   if(s[i]=='.')
           {
            ++count;
            }
             if(i>0 && s[i]!='.')
            {
                if(s[i-1]=='0' &&  temp==0)
                {
                    return false;
                }
            }
            if(s[i]!='.')
            {
                temp=temp*10+(s[i]-'0');
            }
           
            if(temp>255)
            {
                return false;
            }
            if(s[i]=='.')
            {
                temp=0;
            }
            if(i==0 && s[i]=='.')
            {
               return false; 
            }
            if(i>0 && s[i]=='.' && s[i-1]=='.')
            {
                return false;
            }
            if(count>=4)
            {
                return false;
            }
        }
        if(count<3)
        {
            return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends