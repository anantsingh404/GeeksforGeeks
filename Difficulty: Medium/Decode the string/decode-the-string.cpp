class Solution {
  public:
    string decodedString(string &s) {
        
      stack<string> st;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]==']'){
                string str;
                while(st.top()!="["){
                    str=st.top()+str;
                    st.pop();
                } 
                st.pop();
           string numStr;
            while (!st.empty() && st.top().size() == 1 && isdigit(st.top()[0])) {
                numStr += st.top();
                st.pop();
            }
            reverse(numStr.begin(), numStr.end()); 
            int num = stoi(numStr);
                string res;
                for(int k=0;k<num;k++)
                 res+=str;
                st.push(res);
            } else {
                st.push(string("") + s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;  
    }
};