class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
         int n=arr.size();
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int x=arr[i]%(n+1);
            arr[x-1]+=n+1;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]/(n+1)==0)
            {
                mini=i+1;
            }
            if(arr[i]/(n+1)==2)
            {
                maxi=i+1;
            }
        }
        return {maxi,mini};
    }
};