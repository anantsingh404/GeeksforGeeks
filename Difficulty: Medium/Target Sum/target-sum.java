class Solution {
    int n;
    int solve(int idx,int arr[],int [][]dp,int sum)
    {
        if(idx>=n)
        {
            if(sum==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int ans=0;
        if(arr[idx]<=sum){
            ans+=solve(idx+1,arr,dp,sum-arr[idx]);
        }
        ans+=solve(idx+1,arr,dp,sum);
        return dp[idx][sum]=ans;
        
    }
    public int totalWays(int[] arr, int target) {
        // code here
        n=arr.length;
        int sum=0;
        for(int i=0;i<arr.length;i++)
        {
          sum+=arr[i];
        }
        if((sum-target)%2==1)
        {
            return 0;
        }
        sum=(sum-target)/2;
        int dp[][]=new int[n][sum+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(0,arr,dp,sum);
    }
}