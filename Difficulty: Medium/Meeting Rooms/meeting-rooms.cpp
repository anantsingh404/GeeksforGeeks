//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i++)
        {
            vp.push_back({arr[i][1],arr[i][0]});
            
        }
        sort(vp.begin(),vp.end());
        int start=vp[0].second;
        int end=vp[0].first;
        int count=1;
        for(int i=1;i<arr.size();i++)
        {
            if(end>vp[i].second)
            {
                end=max(vp[i].first,end);
            }
            else
            {
                ++count;
                start=vp[i].second;
                end=vp[i].first;
            }
        }
       // cout<<count<<endl;
        return count==arr.size();
        
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends