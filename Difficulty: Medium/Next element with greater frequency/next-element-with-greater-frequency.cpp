class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            
            while(!st.empty() && mp[arr[i]]>=mp[st.top()] )
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(arr[i]);
            }
            else
            {
                ans[i]=st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
