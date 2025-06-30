class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<int,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
            if(i==k-1)
            {
                if(mp.size()==k-1)
                {
                    ++ans;
                }
            }
            if(i>k-1)
            {
                --mp[s[j]-'a'];
                if(mp[s[j]-'a']==0)
                {
                    mp.erase(s[j]-'a');
                }
                if(mp.size()==k-1)
                {
                    ++ans;
                }
                j++;
            }
        }
        return ans;
    }
};