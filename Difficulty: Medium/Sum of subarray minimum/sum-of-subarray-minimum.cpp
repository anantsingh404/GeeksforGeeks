class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
          vector<int>left(n,1);
        vector<int>right(n,1);
        const int MOD=1e9+7;
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
            long long prod=(left[i]*right[i])%MOD;
            prod=(prod*arr[i])%MOD;
            res=(res+prod)%MOD;
        }
        return res%MOD;
    }
};