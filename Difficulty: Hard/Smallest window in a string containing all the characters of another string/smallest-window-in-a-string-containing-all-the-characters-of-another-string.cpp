//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>dp(26,0);
        int ans=1e6;
        string res="";
        for(int i=0;i<p.size();i++)
        {
            dp[p[i]-'a']++;
        }
        vector<int>dp1(26,0);
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            dp1[s[i]-'a']++;
            while(j<i && dp1[s[j]-'a']>dp[s[j]-'a'])
            {
                dp1[s[j]-'a']--;
                j++;
            }
            bool anss=true;
            for(int i=0;i<26;i++)
            {
                if(dp[i]>dp1[i])
                {
                    anss=false;
                }
            }
            if(i-j+1<ans && anss)
            {
                res=s.substr(j,i-j+1);
                 ans=min(ans,i-j+1);
            }
           
        }
        if(ans<1e6)
        {
            return res;
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends