class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int maxi=0;
        int n=arr.size();
        int mm=0;
        for(int i=0;i<n;i++)
        {
            mm=max(mm,arr[i][1]+2);
        }
        vector<int>dp(mm,0);
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i][0];
            int y=arr[i][1];
            ++dp[x];
            --dp[y+1];
            
        }
        maxi=dp[0];
        for(int i=1;i<mm;i++)
        {
            dp[i]=dp[i]+dp[i-1];
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};
