class Solution {
  public:
    int minParentheses(string & st) {
        // code here
        stack<char>s;
        int n=st.size();
        for(char x:st)
        {
            if(!s.empty() && s.top()=='(' && x==')')
            {
                s.pop();
            }
            else
            {
                s.push(x);
            }
        }
        return s.size();
    }
};