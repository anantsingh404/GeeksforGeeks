class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        priority_queue<pair<int,int>>pq;
        sort(arr.begin(),arr.end());
        int i=0;
        int n=arr.size();
        while(i<n)
        {
            int j=i;
            while(j<n && arr[j]==arr[i])
            {
                j++;
            }
            pq.push({j-i,arr[i]});
            i=j;
        }vector<int>ans;
        while(!pq.empty() && ans.size()<k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
