class Solution {
  public:
  bool check(int mid,vector<int>&arr,int k)
  {
      int n=arr.size();
      int sum=0;
      int count=1;
      for(int i=0;i<n;i++)
      {
          sum+=arr[i];
          if(sum>mid)
          {
              ++count;
              sum=arr[i];
          }
      }
      return count<=k;
  }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int ans=INT_MAX;
        
        int mini=*max_element(arr.begin(),arr.end());
        int maxi=1e9;
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
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
        return ans;
        
    }
};