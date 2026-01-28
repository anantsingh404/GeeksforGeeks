class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char>q;
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
          mp[s[i]]++;
          if(mp[s[i]]==1)
          {
              q.push(s[i]);
          }
          while(!q.empty() && mp[q.front()]>1)
          {
              q.pop();
          }
          if(q.empty())
          {
              ans.push_back('#');
          }
          else
          {
              ans.push_back(q.front());
          }
        }
        return ans;
    }
};