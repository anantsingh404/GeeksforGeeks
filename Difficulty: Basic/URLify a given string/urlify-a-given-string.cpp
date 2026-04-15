class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};