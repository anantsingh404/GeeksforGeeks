class Solution {
  public:
  bool check(int mid,vector<int>&arr,int k)
  {   int n=arr.size();
      int count=1;
      int prev=arr[0];
      for(int i=1;i<n;i++)
      {
          if((arr[i]-prev)>=mid)
          {
              ++count;
              prev=arr[i];
          }
      }
      return count>=k;
  }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=0;
        int ans=0;
        int maxi=arr[n-1];
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(check(mid,arr,k))
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
