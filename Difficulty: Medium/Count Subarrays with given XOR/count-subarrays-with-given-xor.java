class Solution {
    public long subarrayXor(int arr[], int k) {
        // code here
            long ans = 0;
        long exor = 0;
        int n = arr.length;

        HashMap<Long, Integer> mp = new HashMap<>();
        mp.put(0L, 1);
        for (int i = 0; i < n; i++) 
        {
            exor = exor ^ arr[i];
            long temp = exor ^ k;

            ans += mp.getOrDefault(temp, 0);

            mp.put(exor, mp.getOrDefault(exor, 0) + 1);
        }
        return ans;
    
    }
}