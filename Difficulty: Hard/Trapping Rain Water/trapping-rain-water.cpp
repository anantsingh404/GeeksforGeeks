//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>left(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(arr[i],left[i-1]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],arr[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {  if(max(left[i],right[i])==arr[i])
        {
            continue;
        }  // cout<<ans<<endl;
            ans+=abs(min(left[i],right[i])-arr[i]);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends