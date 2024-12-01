//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(string pat,vector<int>&psl)
{
    int i=0;
    int j=1;
    while(i<pat.size() && j<pat.size())
    {
        if(pat[i]==pat[j])
        {
            psl[j]=i+1;
            i++;
            j++;
        }
        else if(i!=0)
        {
            i=psl[i-1];
        }
        else
        {
            j++;
        }
    }
}
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int>psl(pat.size(),0);
            solve(pat,psl);
            int m=pat.size();
            int i=0;
            int j=0;
            vector<int>ans;
            while(i<txt.size())
            {
                if(pat[j]==txt[i])
                {
                    ++i;
                    ++j;
                }
                if(j==m)
                {
                    ans.push_back(i-j);
                    j=psl[j-1];
                }
                else if(i<txt.size() and txt[i]!=pat[j]){
                if(j==0){
                    i++;
                }
                else {
                    j= psl[j-1];
                }
            }
}return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends