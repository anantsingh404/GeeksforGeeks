class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
       int n=pat.size();
       int m=tar.size();
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0){
            if(pat[i]==tar[j])
            {
                 --j;
                 --i;
            }
            else
            {
                i-=2;
            }
            if(i<=-1 && j<0)
            {
                return true;
            }
           
        }
        return j<0;
    }
};