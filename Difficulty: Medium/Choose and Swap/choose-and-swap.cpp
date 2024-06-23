//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string chooseandswap(string s) {
        // Code Here
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=i+1;
            }
        }
        char x;
        char y;
        //cout<<mp['a']<<mp['b']<<endl;
        for(int i=0;i<s.size();i++)
        {
            for(char j='a';j<s[i];j++)
            {
                if(mp[j]>mp[s[i]])
                {
                    x=s[i];
                    y=j;
                    break;
                }
            }
            if(x>='a' && x<='z')
            {
                break;
            }
        }
        //cout<<x<<y<<endl;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==x)
            {
                s[i]=y;
            }
            else if(s[i]==y)
            {
                s[i]=x;
            }
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}

// } Driver Code Ends