class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double>pq(arr.begin(),arr.end());
        double sum=0.0000;
        sum=accumulate(arr.begin(),arr.end(),0);
        double half=sum/2;int count=0;
        while(sum>half)
        {
            double x=pq.top();
            pq.pop();
            sum-=x/2.0000;
            x/=2.0000;
            pq.push(x);++count;
            
        }
        return count;
        
    }
};