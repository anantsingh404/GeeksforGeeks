//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class trie{
    public:
    trie * link[2];
    trie()
    {
        link[0]=NULL;
        link[1]=NULL;
    }
};
class Solution {
  public:
  trie * root;
    void insert(int num)
    {
        trie * cur=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(cur->link[bit]==NULL)
            {
                cur->link[bit]=new trie();
                
            }
            cur=cur->link[bit];
            
        }
    }
    int findMax(int num) {
      trie * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> link[!bit]) {
          maxNum = maxNum | (1 << i);
          node = node -> link[!bit];
        } else {
          node = node -> link[bit];
        }
      }
      return maxNum;
    }
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,vector<vector<int>> &queries) {
          
      vector < long long > ans(Q, 0);   
      vector < pair < int, pair < int, int >>> offlineQueries;
      sort(arr.begin(), arr.end());
      int index=0;
      for (auto & it: queries) {
    offlineQueries.push_back({
      it[1],
      {
        it[0],
        index++
      }
    });
  }
   sort(offlineQueries.begin(), offlineQueries.end());
   int i = 0;
  int n = arr.size();
  root=new trie();

  for (auto & it: offlineQueries) {
    while (i < n && arr[i] <= it.first) {
      insert(arr[i]);
      i++;
    }
    if (i != 0) ans[it.second.second] = findMax(it.second.first);
    else ans[it.second.second] = -1;
  }
  return ans;
   
   
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends