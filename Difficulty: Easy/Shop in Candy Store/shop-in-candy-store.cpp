class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int sum=0;
        int i=0;
        int n=prices.size();
        int j=n-1;
        while(i<n && i<=j)
        {
          sum+=prices[i];
          j-=k;
          i++;
        }
        int sum1=0;
        j=0;
        i=n-1;
        while(i>=j && i>=0)
        {
            sum1+=prices[i];
            j+=k;
            --i;
        }
        return {sum,sum1};
        
    }
};