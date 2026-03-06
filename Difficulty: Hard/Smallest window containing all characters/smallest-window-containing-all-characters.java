class Solution {
    public static String minWindow(String s, String p) {

        int n = s.length();
        int ans = 100000009;

        HashMap<Character,Integer> mp1 = new HashMap<>();
        HashMap<Character,Integer> mp2 = new HashMap<>();

        int start = -1;
        int end = -1;

        for(int i = 0; i < p.length(); i++)
        {
            char x = p.charAt(i);
            mp1.put(x, mp1.getOrDefault(x,0) + 1);
        }

        int i = 0;
        int j = 0;

        while(i < n)
        {
            char x = s.charAt(i);
            mp2.put(x, mp2.getOrDefault(x,0) + 1);

            while(j < i && mp2.getOrDefault(s.charAt(j),0) > mp1.getOrDefault(s.charAt(j),0))
            {
                mp2.put(s.charAt(j), Math.max(0, mp2.getOrDefault(s.charAt(j),0) - 1));
                j++;
            }

            boolean ok = true;

            for(char xx = 'a'; xx <= 'z'; xx++)
            {
                if(mp1.getOrDefault(xx,0) > mp2.getOrDefault(xx,0))
                {
                    ok = false;
                    break;
                }
            }

            if(ok == true)
            {
                if(i - j + 1 < ans)
                {
                    start = j;
                    end = i;
                    ans = Math.min(ans, i - j + 1);
                }
            }

            i++;
        }

        if(start == -1) return "";

        return s.substring(start, end + 1);
    }
}