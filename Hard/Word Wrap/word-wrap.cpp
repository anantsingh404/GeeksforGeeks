//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int solve(vector<int>&nums,int k,int idx,vector<int>&dp)
{
    if(idx>=nums.size())
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=INT_MAX;
    int sum=0;
    for(int i=idx;i<nums.size();i++)
    {
        sum+=nums[i];
         if(k>=sum && i==nums.size()-1)
        {  
           ans=min(ans,solve(nums,k,i+1,dp)); 
        }
        if(k>=sum)
        {  int x=k-sum;
           x=x*x;
           ans=min(ans,x+solve(nums,k,i+1,dp)); 
        }
        ++sum;
    }
    return dp[idx]=ans;
}
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        vector<int>dp(nums.size(),-1);
        return solve(nums,k,0,dp);
    } 
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends