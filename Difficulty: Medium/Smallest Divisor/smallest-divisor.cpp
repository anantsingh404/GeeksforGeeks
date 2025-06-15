class Solution {
  public:
  bool s(vector<int>&arr,int mid,int k)
  {
      long long sum=0;
      for(int i=0;i<arr.size();i++
      )
      {   int x=arr[i]/mid;
          if(arr[i]%mid)
          {
              
              ++x;
          }
          sum+=x;
      }
      return sum<=k;
  }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int mini=1;
        int maxi=1e8;
        int ans=INT_MAX;
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(s(arr,mid,k))
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
