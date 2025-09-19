class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=-1;
            }
            else
            {
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i]=n;
            }
            else
            {
                right[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
      
        for(int i=0;i<n;i++)
        {
             int len = right[i] - left[i]-1 ;
        if (len >= arr[i]) {
            ans = max(ans, len);
        }
        }
       
        return ans;
        
        
    }
};