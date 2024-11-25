//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
         long long ans=INT_MIN;
	    long long prod=1;
	    for(int i=0;i<n;i++)
	    {
	        prod=prod*arr[i];
	        ans=max(ans,prod);
	        if(prod==0)
	        {
	            prod=1;
	        }
	    }
	    prod=1;
	    for(int i=n-1;i>=0;i--)
	    {
	        prod=prod*arr[i];
	        ans=max(ans,prod);
	        if(prod==0)
	        {
	            prod=1;
	        }
	    }
	    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends