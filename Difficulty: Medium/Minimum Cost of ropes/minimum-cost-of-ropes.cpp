class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        int sum=0;
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
        pq.pop();
        pq.push(x+y);
        sum+=(x+y);
        }
        return sum;
    }
};