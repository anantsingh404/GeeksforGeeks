class Solution {
  public:
    int countStrings(string &s) {
        // code here
       int count=0;
       vector<int>mp(26,0);
       int n=s.size();
       int d=0;
       for(int i=0;i<n;i++)
       {
           mp[s[i]-'a']+=1;
           if(mp[s[i]-'a']>1 && d==0)
           {
               d=1;
               ++count;
           }
           
       }
       count+=(n*(n-1))/2;
      
       for(int i=0;i<26;i++)
       {
          if(mp[i]>0)
          {
              count-=(mp[i]*(mp[i]-1))/2;
          }
       }
       return count;
       
       
       
       
    }
};
