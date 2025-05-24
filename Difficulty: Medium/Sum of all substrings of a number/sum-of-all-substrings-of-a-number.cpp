class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {   string x;
            for(int j=i;j<n;j++)
            {
                x.push_back(s[j]);
                int y=stoi(x);
                sum+=y;
            }
        }
        return sum;
    }
};