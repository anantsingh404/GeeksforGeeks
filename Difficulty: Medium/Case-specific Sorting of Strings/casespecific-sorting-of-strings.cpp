class Solution {
  public:
    string caseSort(string& s) {
        // code here
         vector<char> lower, upper;
    for (char c : s) {
        if (islower(c)) lower.push_back(c);
        else upper.push_back(c);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int li = 0, ui = 0;
    string result;
    for (char c : s) {
        if (islower(c)) result.push_back(lower[li++]);
        else result.push_back(upper[ui++]);
    }

    return result;
    }
};