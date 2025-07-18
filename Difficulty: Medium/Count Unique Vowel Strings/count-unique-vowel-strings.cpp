class Solution {
  public:
  int solve(int n)
  {
      if(n==0)
      {
          return 1;
      }
      return n*solve(n-1);
      
  }
    int vowelCount(string& s) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                mp[s[i]-'a']++;
            }
        }
        if(mp.size()==0)
        {
            return 0;
        }
        int x=solve(mp.size());
        for(auto itr:mp)
        {
            x*=itr.second;
        }
        return x;
    }
};