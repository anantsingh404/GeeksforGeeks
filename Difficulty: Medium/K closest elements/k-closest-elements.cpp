class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n=arr.size();
        vector<int>ans;
        int idx1=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int idx2=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(idx1==n)
        {
            sort(arr.begin(),arr.end());
            for(int i=n-1;i>=n-k;i--)
            {
                ans.push_back(arr[i]);
                //cout<<ans.size()<<endl;
                
            }
            return ans;
        }
        int count=0;
        if(arr[idx2]==x || arr[idx2]==arr[idx1])
        {
            --idx2;
        }
        int i=idx2;
        int j=idx1;
        //cout<<i<<" "<<j<<endl;
       while(i>=0 && j<n && count<k)
       {
           if(abs(arr[i]-x)<abs(arr[j]-x))
           {   ans.push_back(arr[i]);
               ++count;
                // cout<<ans.size()<<endl;
               --i;
           }
           else if(abs(arr[i]-x)==abs(arr[j]-x) && arr[i]>arr[j])
           {
              ans.push_back(arr[i]);
               ++count;
                // cout<<ans.size()<<endl;
               --i; 
           }
           else
           {  ans.push_back(arr[j]);
            // cout<<ans.size()<<endl;
               ++count;
               ++j;
           }
       }
       if(count==k)
       {
           return ans;
       }
       while(j<n && count<k)
       {
           ans.push_back(arr[j]);
           j++;
           ++count;
       }
       while(i>=0 && count<k)
       {
           ans.push_back(arr[i]);
           --i;
           ++count;
       }
       return ans;
        
    }
};