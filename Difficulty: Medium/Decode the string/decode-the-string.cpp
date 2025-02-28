//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
         string ans;
    stack<string> st;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        if (s[i] == ']') {
            string decodedStr;
            
            while (!st.empty() && st.top() != "[") {
                decodedStr = st.top() + decodedStr;
                st.pop();
            }
            
            st.pop(); // Remove '['
            
            string num = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                num = st.top() + num;
                st.pop();
            }
            
            int repeatCount = stoi(num);
            string expandedStr;
            for (int j = 0; j < repeatCount; j++) {
                expandedStr += decodedStr;
            }
            
            st.push(expandedStr);
        } else {
            st.push(string(1, s[i]));
        }
    }
    
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends