class Solution {
   public int countSubstr(String s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

private int atMostK(String s, int k) {
    if (k < 0) {
        return 0;
    }

    int[] freq = new int[26];
    int left = 0;
    int distinct = 0;
    int ans = 0;

    for (int right = 0; right < s.length(); right++) {
        int c = s.charAt(right) - 'a';
        if (freq[c] == 0) {
            distinct++;
        }
        freq[c]++;

        while (distinct > k) {
            int lc = s.charAt(left) - 'a';
            freq[lc]--;
            if (freq[lc] == 0) {
                distinct--;
            }
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}
}