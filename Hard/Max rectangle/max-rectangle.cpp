//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int histo(vector<int>arr)
  {   int n=arr.size();
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
        return res;

  }
    int maxArea(int arr[MAX][MAX], int n, int m) {
        int maxi=0;
        vector<int>ans(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    ans[j]++;
                }
                else
                {
                    ans[j]=0;
                }
            }
            int longest=histo(ans);
            maxi=max(maxi,longest);
        }
        return maxi;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends