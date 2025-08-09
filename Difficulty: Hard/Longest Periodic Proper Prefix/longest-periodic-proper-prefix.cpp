class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
         int n = s.size();
        int i=0;
        int j=n-1;
        int pos = n-1;
        int ans = 0;
        while(j<n && pos>0){
            if(s[i]==s[j]){
                i++;
                j++;
                ans++;
            }
            else{
                i=0;
                pos--;
                j=pos;
                ans = 0;
            }
        }
        if(pos==0) return -1;
        return n-ans;
    }
};