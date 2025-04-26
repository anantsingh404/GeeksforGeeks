//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
       // vector<int>ans;
        long long ans=0;
        for(int i=0;i<n-2;i++)
        {
           
           for(int j=i+1;j<n-1;j++)
           {
               int x=lower_bound(arr+j+1,arr+n,sum-arr[i]-arr[j])-arr;
               --x;
              
                   ans+=x-j;
               
           }
           
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends