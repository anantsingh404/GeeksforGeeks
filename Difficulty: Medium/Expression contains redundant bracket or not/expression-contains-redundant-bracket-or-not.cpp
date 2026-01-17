class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]==')'){
                int count = 0;
                while(!st.empty()){
                    char x =st.top();
                    st.pop();
                    if(x == '(' && count<=1){
                        return true;
                    }else if(x=='(')
                    {
                        break;
                    }else{
                        
                        count++;
                    }
                }
            }else{
                st.push(s[i]);
            }
            i++;
        }
        return false;
    }
};
