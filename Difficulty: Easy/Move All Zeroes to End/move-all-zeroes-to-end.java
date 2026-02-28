class Solution {
    void pushZerosToEnd(int[] arr) {
        // code here
          int i=0;
        int j=0;
        while(i<arr.length)
        {
           if(arr[i]!=0)
           {
               arr[j++]=arr[i];
               
           }
           i++;
        }
        i=j;
        while(i<arr.length){
            arr[i]=0;
            i++;
        }
    }
}