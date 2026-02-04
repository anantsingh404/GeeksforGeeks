class Solution {
  public:
  bool check(vector<int>&stalls,int mid,int k)
  {
      int last=stalls[0];
      --k;
      for(int i=1;i<stalls.size();i++)
      {
          if(stalls[i]-last>=mid)
          {
              --k;
              last=stalls[i];
          }
      }
      return k<=0;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int mini=0;
        int maxi=INT_MAX;
        int ans=-1;
        while(mini<=maxi)
        {
          int mid=(mini+maxi)/2;
          if(check(stalls,mid,k))
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