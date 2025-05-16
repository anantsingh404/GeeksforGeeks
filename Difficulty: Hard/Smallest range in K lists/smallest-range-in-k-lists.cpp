//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
      vector<pair<int,int>>vp;
      int n=arr.size();
      for(int i=0;i<arr.size();i++)
      {
          for(int j=0;j<arr[i].size();j++)
          {
              vp.push_back({arr[i][j],i});
          }
      }
      sort(vp.begin(),vp.end());
      vector<int>ans;
      unordered_map<int,int>mp;
      int j=0;
      int i=0;
      while(i<vp.size())
      {
          mp[vp[i].second]++;
          while(j<=i && mp.size()==n && mp[vp[j].second]>1)
          {
              --mp[vp[j].second];
              if(mp[vp[j].second]==0)
              {
                  mp.erase(mp[vp[j].second]);
              }
              j++;
          }
          if(ans.size()==0 && mp.size()==n)
          {
              ans={vp[j].first,vp[i].first};
          }
          else if(vp[i].first-vp[j].first< ans[1]-ans[0] && mp.size()==n)
          {
              ans={vp[j].first,vp[i].first};
          }
          i++;
          
      }
      return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends