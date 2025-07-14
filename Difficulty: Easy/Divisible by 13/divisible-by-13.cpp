class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int i=0;
        int dig=0;
        while(i<s.size())
        {
            dig=dig*10+s[i]-'0';
            if(dig>=13)
            {
                dig=dig%13;
            }
            i++;
            
        }
        if(dig==0)
        {
            return true;
        }
        return false;
    }
};