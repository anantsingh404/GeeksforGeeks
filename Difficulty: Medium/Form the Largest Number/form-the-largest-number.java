class Solution {
    public String findLargest(int[] arr) {
        // code here
         // Step 1: convert int[] to Integer[]
        Integer[] nums = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            nums[i] = arr[i];
        }
        // Step 2: sort using Comparator
        Arrays.sort(nums, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                String x = a.toString();
                String y = b.toString();
                return (y + x).compareTo(x + y); // descending
            }
        });
          // Step 3: concatenate result
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            ans.append(nums[i]);
        }

        // Step 4: handle leading zeros
        if (ans.charAt(0) == '0') {
            return "0";
        }

        return ans.toString();
        
        
    }
}