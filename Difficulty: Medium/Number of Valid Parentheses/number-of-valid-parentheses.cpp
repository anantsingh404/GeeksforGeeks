class Solution {
  public:
  int solve(int o,int n)
  {
      if(n==0 && o==0)
      {  // cout<<1<<endl;
          return 1;
      }
      if(n==0)
      {
          return 0;
      }
      int ans=0;
      if(o>0)
      {
          ans+=solve(o-1,n-1);
      }
      return ans+=solve(o+1,n-1);
  }
    int findWays(int n) {
        // code here
        int o=0;
        return solve(o,n);
    }
};