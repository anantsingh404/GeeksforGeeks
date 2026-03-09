class Solution {
    public String largestSwap(String s) {
        // code here
          HashMap<Integer, Integer> mp = new HashMap<>();
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            int digit = s.charAt(i) - '0';
            if (!mp.containsKey(digit)) {
                mp.put(digit, i);
            }
        }

        char[] arr = s.toCharArray();

        for (int i = 0; i < n; i++) {
            int x = arr[i] - '0';

            for (int j = 9; j > x; j--) {
                if (mp.containsKey(j) && mp.get(j) > i) {
                    int idx = mp.get(j);

                    char temp = arr[i];
                    arr[i] = arr[idx];
                    arr[idx] = temp;

                    return new String(arr);
                }
            }
        }

        return s;
    }
}