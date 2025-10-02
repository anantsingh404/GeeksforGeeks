class Solution {
  public:
  int n;
  void solve(int idx,vector<int>&arr,vector<string>&res,vector<string>&temp,string &flag)
  {
      if(idx==n)
      {
          res.push_back(flag);
          return ;
      }
      
      if(arr[idx]<0 || arr[idx]>7)
      {
          solve(idx+1,arr,res,temp,flag);
      }
          for(int j=0;j<temp[arr[idx]].size();j++)
          {
              flag.push_back(temp[arr[idx]][j]);
              solve(idx+1,arr,res,temp,flag);
              flag.pop_back();
          }
      
  }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
           vector<string>temp;n=arr.size();
           vector<string>res;
            string flag="";
;          temp.push_back("abc");
         temp.push_back("def");
          temp.push_back("ghi");
           temp.push_back("jkl");
            temp.push_back("mno");
             temp.push_back("pqrs");
              temp.push_back("tuv");
               temp.push_back("wxyz");
               for(int i=0;i<n;i++)
               {
                   arr[i]=arr[i]-2;
               }
               solve(0,arr,res,temp,flag);
               return res;
    }
};