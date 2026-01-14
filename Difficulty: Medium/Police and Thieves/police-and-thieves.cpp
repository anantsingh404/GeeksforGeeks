class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        queue<int>pq1,pq2;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
           while(!pq1.empty() && i-pq1.front()>k)
           {
               pq1.pop();
           }
           while(!pq2.empty() && i-pq2.front()>k)
           {
               pq2.pop();
           }
           if(arr[i]=='P')
           {
               if(!pq1.empty())
               {
                   pq1.pop();
                   ++ans;
               }
               else
               {
                   pq2.push(i);
               }
           }
           if(arr[i]=='T')
           {
               if(!pq2.empty())
               {
                   pq2.pop();
                   ++ans;
               }
               else
               {
                   pq1.push(i);
               }
           }
        }
      return ans;  
    }
};