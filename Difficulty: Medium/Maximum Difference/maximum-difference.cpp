//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;
        st.push(0);
        int i=1;
        while(i<n)
        {
            
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
               st.pop(); 
            }
            if(!st.empty())
            {
                left[i]=arr[st.top()];
            }
            st.push(i);
            i++;
        }
        while(!st.empty())
        {
            st.pop();
        }
        i=n-2;
        st.push(n-1);
        
        while(i>=0)
        {
           
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
               st.pop(); 
            }
            if(!st.empty())
            {
                right[i]=arr[st.top()];
            }
            st.push(i);
            i--;  
        }
        vector<int>ans(n,0);
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
          ans[i]=abs(left[i]-right[i]);  
          res=max(res,ans[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends