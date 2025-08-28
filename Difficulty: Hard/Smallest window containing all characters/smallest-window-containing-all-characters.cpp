class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        int n=s.size();
        int ans=INT_MAX;
        int st=-1;
        int en=-1;
        unordered_map<int,int>mp1;
        for(int i=0;i<p.size();i++)
        {
            mp1[p[i]-'a']++;
        }
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        while(i<n)
        {
           mp[s[i]-'a']++;
           while(j<i && mp[s[j]-'a']>mp1[s[j]-'a'])
           {
               --mp[s[j]-'a'];
               j++;
           }
           bool temp=true;
           for(auto itr:mp1)
           {
               if(mp[itr.first]<mp1[itr.first])
               {
                   temp=false;
                   break;
               }
           }
           if(temp)
           {
               if(ans>i-j+1)
               {
                   st=j;
                   en=i;
                   ans=i-j+1;
                   
               }
           }
           i++;
        }
        if(st!=-1)
        {
            return s.substr(st,en-st+1);
        }
        return "";
    }
};