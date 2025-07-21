class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<0)
            {
                arr[i]=0;
            }
        }
        for(int i=0;i<arr.size();i++)
        {  
            int x=arr[i]%(10000000);
            if(x>0 && x<=n)
            {   if(arr[x-1]<1e7){
                arr[x-1]+=1e7;
            }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]<1e7)
            {
                return i+1;
            }
        }
        return n+1;
    }
};