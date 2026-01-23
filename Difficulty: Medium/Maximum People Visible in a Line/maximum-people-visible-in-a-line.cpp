class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            if(!st.empty())
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
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i]=st.top();
            }
            st.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,right[i]-left[i]-1);
        }
        return maxi;
        
    }
};