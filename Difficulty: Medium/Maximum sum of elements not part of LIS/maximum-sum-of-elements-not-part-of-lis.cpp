class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int lis=1;
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>sum(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {  if(dp[i]<dp[j]+1){
                    dp[i]=max(dp[i],dp[j]+1);
                    sum[i]=sum[j]+arr[i];
                    lis=max(lis,dp[i]);
                }
                
                else if(dp[i]==dp[j]+1 && sum[i]>sum[j]+arr[i])
                {    sum[i]=sum[j]+arr[i];
                     lis=max(lis,dp[i]);
                }
                }
            }
        }
        
       int r=accumulate(arr.begin(),arr.end(),0);
       int mini=INT_MAX;
       
       for(int i=0;i<n;i++)
       {
           if(dp[i]==lis)
           {
               mini=min(mini,sum[i]);
           }
       }
      // cout<<mini<<endl;
       return r-mini;
        
    }
};