//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:
  int getlps(string &s) {

    int n=s.size();
      
      vector<int>lps(n,0);
      int i=1, j=0;
      
      while(i<n and j<n){
          if(s[i]==s[j]){
              lps[i]=j+1;
              i++;j++;
          }
          else{
              if(j!=0){
                 j= lps[j-1];
              }
              else{
                  lps[i]=0;
                  i++;
              }
              
          }
      }

      return lps[n-1];
  }
   
	int lps(string s) {
	    // Your code goes here
	     return getlps(s);
       
      
	}
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends