//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int cnt=0;
       int i=0;
       int j=0;
       int n=arr.size();
       sort(arr.begin(),arr.end());
       while(i<n)
       {
          int x=lower_bound(arr.begin(),arr.end(),arr[i]-k)-arr.begin();
          int y=upper_bound(arr.begin(),arr.end(),arr[i]-k)-arr.begin();
          cnt+=y-x;
          i++;
          
       }
       return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends