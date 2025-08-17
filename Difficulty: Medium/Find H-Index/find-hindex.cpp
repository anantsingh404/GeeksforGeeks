class Solution {
  public:
  bool check(int mid,vector<int>&c)
  {
      int n=c.size();
      int count=0;
      for(int i=0;i<n;i++)
      {
          if(c[i]>=mid)
          {
              ++count;
          }
      }
      return count>=mid;
  }
    int hIndex(vector<int>& c) {
        int n=c.size();
        // code here
        sort(c.begin(),c.end());
        int mini=0;
        int ans=0;
        int maxi=c[n-1];
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(check(mid,c))
            {   ans=mid;
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