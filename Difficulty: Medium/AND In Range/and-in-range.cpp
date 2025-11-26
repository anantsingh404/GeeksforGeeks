class Solution {
  public:
  long long c(long long N, long long x) {
    if (N < 0) {
        return 0;
    }

    long long block = 1LL << (x + 1);
    long long half = 1LL << x;

    long long full = (N + 1) / block;
    long long rem = (N + 1) % block;

    long long ans = full * half;
    if (rem > half) {
        ans += rem - half;
    }
    return ans;
}
    int andInRange(int l, int r) {
        // code here
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int x=c(r,i)-c(max(0,l-1),i);
            if(x==r-l+1)
            {
                ans|=(1<<i);
            }
        }
        return ans;
        
    }
};
