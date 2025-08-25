class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        if(s1.size()==s2.size())
        {
            return s1==s2;
        }
        if(s1.size()<s2.size())
        {
            string x=s1;
            s1=s2;
            s2=x;
            
        }
        int j=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[j])
            {
                j++;
            }
        }
        return j>=s2.size();
    }
};