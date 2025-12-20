class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int mini=0;
        int maxi=arr.size()-1;
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;
            if(arr[mid]==k)
            {
                return mid;
            }
            else if(arr[mid]>k)
            {
                maxi=mid-1;
                
            }
            else
            {
                mini=mid+1;
            }
        }
        return mini;
    }
};