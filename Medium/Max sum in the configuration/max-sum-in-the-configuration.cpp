//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long  sum=0;
        long long  tsum=0;
        for(long long i=0;i<n;i++)
        {
            sum+=a[i];
            tsum+=i*a[i];
        }
        long long ans=tsum;
        long long  len=n;
        while(n)
        {
          tsum=tsum+sum-len*a[n-1];
          ans=max(ans,tsum);
         --n;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends