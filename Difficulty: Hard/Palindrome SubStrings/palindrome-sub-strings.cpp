class Solution {
  public:
    int countPS(string &s) 
    {   
        int ans=0;
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            int j=i-1;
            int k=i;
            while(j>=0 && k<n)
            {
                if(s[k]==s[j])
                {
                    ++ans;
                    ++k;
                    --j;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i=0;i<s.size();i++)
        {
            int j=i-1;
            int k=i+1;
            while(j>=0 && k<n)
            {
                if(s[k]==s[j])
                {
                    ++ans;
                    ++k;
                    --j;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};