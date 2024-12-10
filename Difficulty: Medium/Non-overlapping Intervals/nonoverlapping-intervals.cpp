//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &inte) {
        // code here
         sort(inte.begin(),inte.end());
        int count=0;
        int i=0;
        int j=1;
        while(j<inte.size())
        {   if(inte[i][1]<=inte[j][0])
        {
            i=j;
            j++;
        }
        else if(inte[i][1]<=inte[j][1])
        {
            j++;
            ++count;
        }
        else if(inte[i][1]>inte[j][1])
        {
            i=j;
            j++;
            ++count;
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends