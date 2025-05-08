//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int diff=INT_MAX;
        int n=arr.size();
        if(n==2)
        {
            return arr[n-1]+arr[1]-arr[0];
        }
        for(int i=1;i<arr.size();i++)
        {
            diff=min(diff,arr[i]-arr[i-1]);
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=diff)
            {
                return arr[i-1]+diff;
            }
        }
        return arr[n-1]+diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends