class Solution {
    boolean canFormPalindrome(String s) {
        // code here
        int n=s.length();
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++)
        {
          char x=s.charAt(i);
          mp.put(x-'a',mp.getOrDefault(x-'a',0)+1);
        }
        int odd=0;
        for(int val:mp.values())
        {
            if(val%2==1)
            {
                ++odd;
            }
        }
        if(n%2==1 && odd>1)
        {
            return false;
        }
        if(n%2==1 && odd==1)
        {
            return true;
        }
        if(n%2==0 && odd>1)
        {
            return false;
        }
        return true;
    }
}