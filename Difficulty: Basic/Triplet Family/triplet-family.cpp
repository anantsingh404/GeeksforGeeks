//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=2;i<n;i++)
        {
           int j=i-1;
           int k=0;
           while(j>k)
           {
               if(arr[j]+arr[k]==arr[i])
               {
                  return true;
               }
               else if(arr[j]+arr[k]<arr[i])
               {
                   ++k;
               }
               else
               {
                   --j;
               }
           }
        }
        
        
        return false;
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends