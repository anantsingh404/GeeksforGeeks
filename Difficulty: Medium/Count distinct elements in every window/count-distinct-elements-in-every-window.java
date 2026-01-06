class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        // code here
        int n=arr.length;
        ArrayList<Integer>ans=new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        int j=0;
        for(int i=0;i<n;i++)
        {
           if (mp.containsKey(arr[i])) {
    mp.put(arr[i], mp.get(arr[i]) + 1);
} else {
    mp.put(arr[i], 1);
}
           if(i>=k)
           {
               mp.put(arr[j], mp.get(arr[j]) - 1);
               if(mp.get(arr[j])==0)
               {
                   mp.remove(arr[j]); 
               }
               j++;
           }
           if(i>=k-1)
           {
              ans.add(mp.size()); 
           }
        }
        return ans;
    }
}