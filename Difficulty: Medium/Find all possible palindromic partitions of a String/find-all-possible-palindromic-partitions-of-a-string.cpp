class Solution {
  public:
   bool ispal(string &s)
  {
      int i=0;
      int n=s.size()-1;
      while(i<=n)
      {
          if(s[i]!=s[n])
          {
              return false;
          }
          i++;
          n--;
      }
      return true;
  }
  void solve(string &s,int i,vector<vector<string>>&ans,vector<string>flag)
  {
      if(i==s.size())
      {   ans.push_back(flag);
          return;
      }
      for(int j=i;j<s.size();j++)
      {   string x=s.substr(i,j-i+1);
          if(ispal(x))
          {
              flag.push_back(x);
              solve(s,j+1,ans,flag);
              flag.pop_back();
          }
      }
  }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>>ans;
         vector<string>flag;
         solve(s,0,ans,flag);
         return ans;
        
    }
};