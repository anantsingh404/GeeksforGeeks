class Solution {
  public:
  bool Check(long long mid,vector<int>&arr,long long k)
  {
      long long hc=0;
      for(int i=0;i<arr.size();i++)
      {
       if(arr[i]%mid)
      {
          ++hc;
      }
      hc+=arr[i]/mid;
      }
  return hc<=k;
  }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        long long mini=1;
        long long maxi=INT_MAX;
        long long ans=INT_MAX;
        while(mini<=maxi)
        {
            long long mid=(mini+maxi)/2;
            if(Check(mid,arr,k))
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