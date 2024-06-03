//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 // const int MOD=1e9+7;
    int numberOfConsecutiveOnes(int n) {
        // code here
        int MOD=(int)pow(10,9)+7;
        long ans=1;
        int x=0,y=1;
        for(int i=3;i<=n;i++){
            ans=(ans*2+x+y)%MOD;
            x=x%MOD;
            y=y%MOD;
            int temp=x;
            x=y;
            y=y+temp;
        }
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends