//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meet) {
        // code here
        
        sort(meet.begin(),meet.end());
        int maxi=0;
        vector<int>dp(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq1;
        priority_queue<int,vector<int>,greater<>>pq2;
        
        for(int i=0;i<n;i++)
        {
           pq2.push(i);
        }
        for(int i=0;i<meet.size();i++)
        {
            int x=meet[i][0];
            int y=meet[i][1];
            while(!pq1.empty() && pq1.top().first<=meet[i][0])
            {
                pq2.push(pq1.top().second);
                pq1.pop();
            }
            if(!pq2.empty())
            {
                int d=pq2.top();
                dp[d]++;
                 maxi=max(dp[d],maxi);
                pq1.push({meet[i][1],d});
                pq2.pop();
            }
            else
            {
                int m=pq1.top().first;
                int mm=pq1.top().second;
                pq1.pop();
                dp[mm]++;
                maxi=max(dp[mm],maxi);
                pq1.push({m + (y - x), mm});
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                return i;
            }
        }
       
       
        
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends