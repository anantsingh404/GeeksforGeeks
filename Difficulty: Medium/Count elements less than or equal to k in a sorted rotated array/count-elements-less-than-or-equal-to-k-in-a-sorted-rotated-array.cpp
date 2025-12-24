class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int mini=0;
        int maxi=n-1;
        while(mini<maxi)
        {
            int  mid=(mini+maxi)/2;
            
            if(arr[mid]>arr[maxi])
            {
               mini=mid+1; 
            }
            
            else
            {
                maxi=mid;
            }
        }
       // cout<<mini<<endl;
        int count=0;
        count+=upper_bound(arr.begin(),arr.begin()+mini,x)-arr.begin();
       // cout<<count<<endl;
         count+=upper_bound(arr.begin()+mini,arr.end(),x)-(arr.begin()+mini);
         // cout<<count<<endl;
         return count;
    }
};