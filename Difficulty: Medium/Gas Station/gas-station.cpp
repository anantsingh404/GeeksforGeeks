class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int ts=accumulate(cost.begin(),cost.end(),0);
        int tg=accumulate(gas.begin(),gas.end(),0);
        if(ts>tg)
        {
            return -1;
        }
        
         int i=0;
        int j=0;
        int sum=0;
        while(i<n)
        {    sum+=gas[i];
            if(cost[i]<=sum)
            {
                sum-=cost[i];
            }
            else
            {
                sum=0;
                j=i+1;
            }
            i++;
        }
        return j;
    }
};