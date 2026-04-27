class Solution {
    public int smallestSubstring(String s) {
        // code here
        int i=0;
        int j=0;
         int a=0;
         int b=0;
         int c=0;
         int ans=100000000;
         int n=s.length();
        while(i<n)
        {
            if(s.charAt(i)=='0')
            {
                ++a;
            }
            if(s.charAt(i)=='1')
            {
                ++b;
            }
            if(s.charAt(i)=='2')
            {
                ++c;
            }
            while(j<n)
            {    
                char x=s.charAt(j);
                if(x=='0' && a==1)
                {
                   break; 
                }if(x=='1' && b==1)
                {
                   break; 
                }
                if(x=='2' && c==1)
                {
                   break; 
                }
            
                 if(s.charAt(j)=='0')
            {
                --a;
            }
            if(s.charAt(j)=='1')
            {
                --b;
            }
            if(s.charAt(j)=='2')
            {
                --c;
            }
            ++j;
            }
            if(a>0 && b>0 && c>0)
            {
                ans=Math.min(ans,i-j+1);
            }
            i++;
        }
        if(ans==1e8)
        {
            return -1;
        }
        return ans;
    }
};
