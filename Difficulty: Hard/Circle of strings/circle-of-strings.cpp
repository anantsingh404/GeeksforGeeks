//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<arr.size();i++)
        {
            mp1[arr[i][0]]++;
            mp2[arr[i].back()]++;
        }
        if(mp1.size()!=mp2.size())
        {
            return 0;
        }
        for(auto itr:mp1)
        {
            if(mp1[itr.first]!=mp2[itr.first])
            {
                return 0;
            }
            
        }
        unordered_map<char,vector<int>>adj;
        for(int i=0;i<arr.size();i++)
        {
            adj[arr[i][0]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int count=1;
        int n=arr.size();
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            char y=arr[x].back();
            for(auto itr:adj[y])
            {
                if(!vis[itr])
                {   vis[itr]=1;
                    q.push(itr);
                    ++count;
                }
            }
        }
        
        
        return count==n?1:0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends