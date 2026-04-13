class Solution {
    String removeSpaces(String s) {
        // code here
        StringBuilder str=new StringBuilder();
        for(int i=0;i<s.length();i++)
        {
            char x=s.charAt(i);
            if(x!=' ')
            {
              str.append(x); 
            }
        }
        return str.toString();
    }
}