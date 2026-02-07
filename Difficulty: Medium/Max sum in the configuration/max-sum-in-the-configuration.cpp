class Solution {
  public:
    int maxSum(vector<int> &a) {
        // code here
         long long  sum=0;
        long long  tsum=0;
        int n=a.size();
        for(long long i=0;i<n;i++)
        {
            sum+=a[i];
            tsum+=i*a[i];
        }
        long long ans=tsum;
        long long  len=n;
        while(n)
        {
          tsum=tsum+sum-len*a[n-1];
          ans=max(ans,tsum);
         --n;
        }
        return ans;
    }
};