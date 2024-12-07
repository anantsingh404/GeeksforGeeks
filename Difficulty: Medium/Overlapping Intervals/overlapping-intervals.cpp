//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  static bool cmp(vector<int>a,vector<int>b)
  {  if(a[1]==b[1])
  {
      return a[0]<=b[0];
  }
      return a[1]<=b[1];
  }
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int start=arr[0][0];
        int end=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(end>=arr[i][0])
            {
                end=max(end,arr[i][1]);
                
            }
            else
            {   
            vector<int>temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
            start=arr[i][0];
            end=arr[i][1];
                
            }
        }
        vector<int>temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
        
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
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends