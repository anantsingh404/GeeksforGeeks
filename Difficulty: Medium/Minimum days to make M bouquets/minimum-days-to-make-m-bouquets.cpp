class Solution {
  public:
  bool check(int mid,vector<int>&arr,int k,int m)
  {
      int count=0;
      int sum=0;
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]<=mid)
          {
              ++count;
          }
          if(count==k)
          {
              ++sum;
              count=0;
          }
      }
      return sum>=m;
  }
    int minDaysBloom(vector<int> arr, int k, int m) {
        // Code here
        int mini=0;
        int maxi=1e9;
        int ans=-1;
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(check(mid,arr,k,m))
            {
                ans=mid;
                maxi=mid-1;
            }
            else
            {
                mini=mid+1;
            }
        }
        return ans;
    }
    
    
    
    
    
    
    
};