class Solution {
  public:
    string removeKdig(string &S, int k) {
        // code here
          stack<char>s;
        s.push(S[0]);
        int i=1;
        while(i<S.size())
        {   if(s.empty())
            {
            s.push(S[i]);
            i++;
           }
           else  if(s.top()>S[i] && k>0)
            {
                s.pop();
                --k;
            }
            else
            {   
                s.push(S[i]);
                ++i;
            }
        }
        
        while(k)
        {  
            s.pop();
            --k;
        }
        
        string ans="";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        //cout<<ans<<endl;
        
        reverse(ans.begin(),ans.end());
        i=0;
        while(ans[i]=='0')
        {
            i++;
        }
        if(i==ans.size())
        {
            return "0";
        }
        if(ans.empty())
        {
            return "0";
        }
        return ans.substr(i,ans.size()-i);
    }
};