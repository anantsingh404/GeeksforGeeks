//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &inter,
                                       vector<int> &ni) {
        // code here
        inter.push_back(ni);
        sort(inter.begin(),inter.end());
         int start=inter[0][0];
        int end=inter[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<inter.size();i++)
        {
            if(end>=inter[i][0])
            {
                end=max(end,inter[i][1]);
                
            }
            else
            {   
            vector<int>temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
            start=inter[i][0];
            end=inter[i][1];
                
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
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends