class Solution {
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
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++)
        {   for(int j=0;j<m;j++){
            if(mat[i][j]==1)
            {
                dp[i][j]=dp[i-1][j]+1;
            }
        }
        }
        
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
          maxi=max(maxi,histo(dp[i]));
        }
        return maxi;
    }
    
};