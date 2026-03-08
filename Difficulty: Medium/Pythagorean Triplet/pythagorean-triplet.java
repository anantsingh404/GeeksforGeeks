class Solution {
    boolean pythagoreanTriplet(int[] arr) {
        // code here
         int[] mp = new int[1001];

        int i = 0;
        while (i < arr.length) {
            mp[arr[i]]++;
            i++;
        }

        i = 1;
        while (i <= 1000) {

            int j = 1;
            while (j <= 1000) {

                if (mp[i] > 0 && mp[j] > 0) {

                    if (i == j) {

                        if (mp[i] >= 2) {
                            int x = i * i + j * j;
                            int y = (int)Math.sqrt(x);

                            if (y <= 1000 && mp[y] > 0 && y * y == x) {
                                return true;
                            }
                        }

                    } else {

                        int x = i * i + j * j;
                        int y = (int)Math.sqrt(x);

                        if (y <= 1000 && mp[y] > 0 && y * y == x) {
                            return true;
                        }

                    }
                }

                j++;
            }

            i++;
        }

        return false;
    }
}