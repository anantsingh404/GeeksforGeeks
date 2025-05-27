class Solution {
  public:
    vector<int> leafNodes(vector<int>&arr) {
        // code here
        int N=arr.size();
         vector<int>ans;
        stack<int>flag;
        flag.push(arr[0]);
        for(int i=1;i<N;i++)
        {
            if(arr[i]<flag.top())
            {
                flag.push(arr[i]);
            }
            else
            {
                int pre=flag.size();
                int temp=flag.top();
                while(!flag.empty() && arr[i]>flag.top())
                {
                    flag.pop();
                }
                flag.push(arr[i]);
                if(pre>flag.size())
                {
                 ans.push_back(temp);   
                }
            }
        }
        ans.push_back(flag.top());
        return ans;
    }
};