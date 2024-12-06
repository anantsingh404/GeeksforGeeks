//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& ci) {
        // code here
        int n=ci.size();
        sort(ci.begin(),ci.end());
        int ans=0;
        for(int i=ci.size()-1;i>=0;i--)
        {
            if(ci[i]<=n-i)
            {
                ans=max(ans,ci[i]);
                
            }
            else if(ci[i]>n-i)
            {
                ans=max(ans,n-i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends