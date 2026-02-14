class Solution {
  public:
  bool check(long long mid,vector<int>&arr,int k)
  {
      long long count=0;
      long long ans=1;
      for(int i=0;i<arr.size();i++)
      {
          count+=arr[i];
          if(arr[i]>mid)
          {
              return false;
          }
          if(count>mid)
          {
              ++ans;
              count=arr[i];
          }
         
      }
      return ans<=k;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        long long mini=0;
        long long maxi=accumulate(arr.begin(),arr.end(),1ll);
        long long ans=maxi;
        while(mini<=maxi)
        {
            long long mid=(mini+maxi)/2;
            if(check(mid,arr,k))
            {
                ans=mid;
                maxi=mid-1;
            }
            else
            {
                mini=mid+1;
            }
        }
        return (int)ans;
    }
};