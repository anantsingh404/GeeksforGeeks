class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
         int n=s.size();
         stack<char>st;
         for(int i=0;i<n;i++)
         {
             st.push(s[i]);
         }
         int sum=0;
         while(!st.empty())
         {
             int x=mp[st.top()];
             sum+=x;
             st.pop();
             while(!st.empty() && mp[st.top()]<x)
             {
                 sum-=mp[st.top()];
                 st.pop();
             }
         }
         return sum;
         
        
    }
};