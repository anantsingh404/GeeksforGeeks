class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n=a1.size();
        vector<int>s1(n);
        for(int i=0;i<n;i++)
        {
            s1[i]=a1[i]-a2[i];
        }
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=s1[i];
            if(sum==0)
            {
                ans=i+1;
                mp[sum]=i;
                continue;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
            
        }
        return ans;
    }
};