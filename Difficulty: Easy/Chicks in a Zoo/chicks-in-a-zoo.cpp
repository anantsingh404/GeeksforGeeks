//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    vector<long long int>dp(40,0);
	    dp[0]=1;
	    
	    dp[1]=3;
	    dp[2]=9;
	    dp[3]=27;
	    dp[4]=81;
	    dp[5]=243;
	    dp[6]=726;
	    for(int i=7;i<n;i++)
	    {
	       dp[i]=(dp[i-1]-(((dp[i-6])/3))*2)*3;
	    }
	    return dp[n-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends