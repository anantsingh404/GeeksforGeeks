class Solution {
  public:
  int n;
  void solve(string &res,vector<string>&ans){
      if(res.size()==n)
      {
          ans.push_back(res);
          return ;
      }
      res.push_back('0');
      solve(res,ans);
      res.pop_back();
      res.push_back('1');
      solve(res,ans); 
      res.pop_back();
      
      
  }
    vector<string> binstr(int m) {
        // code here
        n=m;
        vector<string>ans;
        string res="";
         solve(res,ans);
        return ans;
    }
};