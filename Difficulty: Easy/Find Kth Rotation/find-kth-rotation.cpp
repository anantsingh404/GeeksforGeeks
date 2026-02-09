class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                return i+1;
            }
        }
        return 0;
    }
};
