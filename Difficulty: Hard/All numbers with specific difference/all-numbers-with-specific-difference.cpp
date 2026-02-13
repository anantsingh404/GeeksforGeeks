class Solution {
  public:
  bool check(int mid,int k)
  {
      string s=to_string(mid);
      int sum=0;
      for(int i=0;i<s.size();i++)
      {
          sum+=s[i]-'0';
      }
      return mid-sum>=k;
      
  }
    int getCount(int n, int k) {
        // code here
        if(k==0)
        {
            return n;
        }
        int mini=0;
        int maxi=n;
        int ans=INT_MAX;
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(check(mid,k))
            {
                ans=mid;maxi=mid-1;
            }
            else
            {
                mini=mid+1;
            }
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return n-ans+1;
    }
};