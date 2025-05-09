//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        int n=s.size();
        int i=0;
        
        while(i<n && k)
        {  int maxi=INT_MIN;
           for(int j=n-1;j>i;j--)
           {
               maxi=max(maxi,s[j]-'1');
           }
           if(maxi+'1'>s[i])
           {
              for(int j=n-1;j>i;j--)
           {  
               if(s[j]==maxi+'1'){
               swap(s[i],s[j]);
               --k;
               break;
           }
           }  
           }
           i++;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends