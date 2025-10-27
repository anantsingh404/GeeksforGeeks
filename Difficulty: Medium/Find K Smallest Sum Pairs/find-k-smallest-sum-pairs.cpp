class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        int n=arr1.size();
       
       int m=arr2.size();
       
    priority_queue<pair<int, pair<int,int>>> pq;

       
       for(int i=0;i<n;i++){
           
           for(int j=0;j<m;j++){
               
               
               int sum=arr1[i]+arr2[j];
               
               if(pq.size()==k){
                   
                   if(sum<pq.top().first){
                       
                       pq.pop();
                       
                       pq.push({sum,{arr1[i],arr2[j]}});
                   }
                   
                   else{
                       
                       break;
                   }
                   
           }
               else {
               
               pq.push({sum,{arr1[i],arr2[j]}});
               
               }
               
             
               
           }
       }
       
       
       vector<vector<int>>ans;
       
       while(!pq.empty()){
           
           ans.push_back({pq.top().second.first,pq.top().second.second});
           
           pq.pop();
       }
       
       reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
