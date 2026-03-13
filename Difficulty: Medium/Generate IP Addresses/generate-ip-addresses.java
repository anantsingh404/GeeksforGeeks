class Solution {

    void solve(int idx, int count, String s, StringBuilder temp, ArrayList<String> ans)
    {
        if(count == 0)
        {
            if(idx >= s.length())
            {
                return;
            }

            String last = s.substring(idx);

            if(last.length() > 1 && last.charAt(0) == '0')
            {
                return;
            }

            int val = Integer.parseInt(last);

            if(val <= 255)
            {
                ans.add(temp.toString() + last);
            }

            return;
        }

        int sum = 0;

        for(int i = idx; i < s.length() && i < idx + 3; i++)
        {
            sum = sum * 10 + (s.charAt(i) - '0');

            if(sum > 255)
            {
                break;
            }

            int len = temp.length();

            temp.append(s.substring(idx, i + 1));
            temp.append('.');

            solve(i + 1, count - 1, s, temp, ans);

            temp.setLength(len);

            if(s.charAt(idx) == '0')
            {
                break;
            }
        }
    }

    public ArrayList<String> generateIp(String s)
    {
        ArrayList<String> ans = new ArrayList<>();
        StringBuilder temp = new StringBuilder();

        if(s.length() < 4 || s.length() > 12)
        {
            return ans;
        }

        solve(0, 3, s, temp, ans);

        return ans;
    }
}