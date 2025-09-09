class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        unordered_map<int,int>mp;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(mp.find(s[i]-'0')==mp.end())
            {
                mp[s[i]-'0']=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            int x=s[i]-'0';
            for(int j=9;j>x;j--)
            {
                if(mp[j]>i)
                {
                  swap(s[i],s[mp[j]]);
                  return s;
                }
            }
        }
        return s;
        
    }
};