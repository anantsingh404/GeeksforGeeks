class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int x=*max_element(b.begin(),b.end());
        vector<int>dp(x+1,0);
        for(int i=0;i<b.size();i++)
        {
            dp[b[i]]++;
        }
        for(int i=1;i<=x;i++)
        {
            dp[i]+=dp[i-1];
        }
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>x)
            {
                ans.push_back(dp[x]);
            }
            else
            {
                ans.push_back(dp[a[i]]);
            }
        }
        return ans;
    }
};