class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int x=__gcd(a,b);
        int lcm=(a*b)/x;
        return {lcm,x};
    }
};