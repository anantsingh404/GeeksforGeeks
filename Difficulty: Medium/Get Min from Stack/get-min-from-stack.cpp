//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  stack<int>st;
  vector<int>dp;
  vector<int>dp1;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
            if(!st.empty())
            {
            dp.push_back(min(x,dp.back()));
            dp1.push_back(max(x,dp1.back()));
            st.push(x);
            }
            else
            {
            dp.push_back(x);
            dp1.push_back(x);
            st.push(x); 
            }
        
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty())
        {
            dp.pop_back();
            dp1.pop_back();
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty())
        {
            return st.top();
        }
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
         if(!st.empty())
        {
            return dp.back();
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends