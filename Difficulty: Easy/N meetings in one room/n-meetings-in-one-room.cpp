//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back({end[i],start[i]});
            
        }
        int count=1;
        sort(ans.begin(),ans.end());
        int starts=ans[0].second;
        int ends=ans[0].first;
        for(int i=1;i<n;i++)
        {
            if(ans[i].second>ends)
            {
                  ends=ans[i].first;
                  ++count;
                
            }
            else
            {
                continue;
            
               
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends