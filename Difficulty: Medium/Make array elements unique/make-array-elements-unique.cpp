//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        int count=0;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int x=arr[i]-arr[i-1];
            if(x<=0)
            {
                arr[i]+=abs(x)+1;
                count+=abs(x)+1;
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
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends