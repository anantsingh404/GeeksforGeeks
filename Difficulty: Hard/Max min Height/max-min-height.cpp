class Solution {
  public:
  bool check(int mid,vector<int>&arr,int k,int w)
  {
      int n=arr.size();
      vector<int>dp(n,0);
      for(int i=0;i<n;i++)
      {   if(i>0)
         {
          dp[i]=dp[i]+dp[i-1];
         }
          if(arr[i]+dp[i]<mid)
          {
              int x=mid-(arr[i]+dp[i]);
              if(x>k)
              {
                  return false;
              }
              k-=x;
              dp[i]=dp[i]+x;
              if(i+w<n)
              {
                  dp[i+w]-=x;
              }
          }
          else
          {
              continue;
          }
      }
      return true;
  }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int mini=0;
        int maxi=*max_element(arr.begin(),arr.end())+k;
        int ans=0;
        while(mini<=maxi)
        {
            int  mid=(mini+maxi)/2;
            if(check(mid,arr,k,w))
            {
                ans=mid;
                mini=mid+1;
            }
            else
            {
                maxi=mid-1;
            }
        }
        return ans;
    }
};