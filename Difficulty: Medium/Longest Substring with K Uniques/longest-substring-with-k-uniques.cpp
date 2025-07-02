class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        int ans=-1;
        int i=0;
        int j=0;
        while(i<n)
        {
            mp[s[i]]++;
            while(j<i && mp.size()>k)
            {
                --mp[s[j]];
                if(mp[s[j]]==0)
                {
                    mp.erase(s[j]);
                }
                j++;
            }
            if(mp.size()==k)
            {
                ans=max(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};