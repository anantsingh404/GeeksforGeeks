class Solution {
  public:
  string stringAdd(const string &a, const string &b) {
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}
bool isValidSumString(const string &s, string a, string b, int start) {
    if (start == s.size()) {
        return true;
    }

    string sum = stringAdd(a, b);
    int sumLen = sum.length();

    if (start + sumLen > s.length() || s.substr(start, sumLen) != sum) {
        return false;
    }

    return isValidSumString(s, b, sum, start + sumLen);
}
    bool isSumString(string &s) {
        // code here
       int n = s.size();

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);

            // Skip leading zero cases
            if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) {
                continue;
            }

            if (isValidSumString(s, a, b, j)) {
                return true;
            }
        }
    }
    return false;
    }
};