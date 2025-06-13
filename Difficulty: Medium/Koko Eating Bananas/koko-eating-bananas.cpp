class Solution {
  public:
  bool check(int mid,vector<int>&arr,int k)
  {
      int n=arr.size();
      for(int i=0;i<n;i++)
      {
         k-=(arr[i]/mid);
         if(arr[i]%mid)
         {
             --k;
         }
         
      }
      return k>=0;
  }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
       int mini=1;
       int maxi=1e7;
       int ans=INT_MAX;
       while(mini<=maxi)
       {
           int  mid=(mini+maxi)/2;
           if(check(mid,arr,k))
           {   // cout<<mid<<endl;
               ans=mid;
               maxi=mid-1;
           }
           else
           {
               mini=mid+1;
           }
       }
        return ans;
    }
};