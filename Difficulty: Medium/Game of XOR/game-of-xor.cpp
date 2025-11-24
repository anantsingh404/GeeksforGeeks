class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(32,0);
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                if(arr[i]&(1<<j))
                {
                    dp[j]+=(i+1)*(n-i);
                }
            }
        }
        int ans=0;
        for(int j=0;j<32;j++)
        {
            if(dp[j]%2)
            {
                ans|=(1<<j);
            }
        }
        return ans;
    }
};