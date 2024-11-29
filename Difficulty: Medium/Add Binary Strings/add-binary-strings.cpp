//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
          int n=s1.size();
     int m=s2.size();
     int i=n-1;
     int j=m-1;
     string ans="";
     int carry=0;
     while(i>=0 || j>=0 || carry)
     {  
         int sum=carry;
         if(i>=0) 
         sum+=s1[i--]-'0';
         if(j>=0)
         sum+=s2[j--]-'0';
         
         ans += (sum%2)+'0';
         carry=sum/2;
         
         
     }
     reverse(ans.begin(),ans.end());
    int count=0;
    while(ans[count]=='0')
    {
        count++;
        
    }
    ans.erase(0,count++);
    
     return ans;
     
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends