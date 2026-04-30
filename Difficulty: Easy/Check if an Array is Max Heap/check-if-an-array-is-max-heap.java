class Solution {
    public boolean isMaxHeap(int[] arr) {
        // code here
        boolean ans=true;
        int n=arr.length;
        for(int i=0;i<arr.length;i++)
        {
            int x=2*i+1;
            int y=2*i+2;
            if(x<n)
            {
                if(arr[i]<arr[x])
                {
                    ans=false;
                }
            }
             if(y<n)
            {
                if(arr[i]<arr[y])
                {
                    ans=false;
                }
            }
            
        }
        return ans;
        
    }
}