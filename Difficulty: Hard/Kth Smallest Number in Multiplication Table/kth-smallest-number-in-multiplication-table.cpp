class Solution {
  public:
   int countLessEqual(int value, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(value / i, n);
        }
        return count;
    }

  
    int kthSmallest(int m, int n, int k) {
        // code here
         int low = 1;
        int high = m * n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(mid, m, n);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
        
    }
};
