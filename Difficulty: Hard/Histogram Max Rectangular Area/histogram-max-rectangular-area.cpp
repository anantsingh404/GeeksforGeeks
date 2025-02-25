//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n=arr.size();
        // Your code here
         vector<int>left(n,1);
        vector<int>right(n,1);
        stack<int>st;
        st.push(0);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=i+1;
            }
            else
            {
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(st.size())
        {
            st.pop();
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i]=n-i;
            }
            else
            {
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,(left[i]+right[i]-1)*arr[i]);
        }
        return (int)res;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends