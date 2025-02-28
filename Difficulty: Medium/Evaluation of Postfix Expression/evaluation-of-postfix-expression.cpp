//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(stoi(arr[i]));
            }
            else if(arr[i]=="*")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x*y);
                
            }
            else if(arr[i]=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
                
            }else if(arr[i]=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
              
                st.pop();
                st.push(x+y);
                
            }
            else if(arr[i]=="-")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(-x+y);
                
            }
            else
            {
                st.push(stoi(arr[i]));
            }
            
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends