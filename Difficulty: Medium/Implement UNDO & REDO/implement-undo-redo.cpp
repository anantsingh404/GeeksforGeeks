class Solution {
  public:
  string ans="";
  stack<char>st;
    void append(char a) {
        // append x into document
        ans.push_back(a);
        
    }

    void undo() {
        // undo last change
        if(!ans.empty())
        {   
            st.push(ans.back());
            ans.pop_back();
        }
    }

    void redo() {
        // redo changes
          if(!st.empty()){
          ans.push_back(st.top());
          st.pop();
          }
          
        
    }

    string read() {
        // read the document
        return ans;
        
    }
};