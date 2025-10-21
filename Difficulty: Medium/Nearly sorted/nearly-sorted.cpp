class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>st;
        int i=0;int j=0;
        while(j<arr.size())
        {
            st.push(arr[j]);
            if(st.size()==k+1){
                arr[i++]=st.top();
                st.pop();
            }
            j++;
        }
        while(!st.empty())
        {
            arr[i++]=st.top();
            st.pop();
        }
    }
};