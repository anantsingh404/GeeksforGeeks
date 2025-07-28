class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n=s.size();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]].first=i;
                mp[s[i]].second=i;
                
            }
            else
            {
                mp[s[i]].second=i;
            }
        }
        vector<int>ans;
        for(auto itr:mp)
        {
            if(itr.second.first!=itr.second.second)
            {
               int sum=0;
               for(int i=itr.second.first+1;i<itr.second.second;i++)
               {
                   sum+=s[i];
               }
               if(sum>0){
               ans.push_back(sum);
               }
               
            }
        }
       
        return ans;
    }
};